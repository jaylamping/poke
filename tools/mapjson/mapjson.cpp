// mapjson.cpp

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::find;
using std::sort;

#include <map>
using std::map;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::ostringstream;

#include <limits>
using std::numeric_limits;

#include "json11.h"
using json11::Json;

#include "mapjson.h"

string version;
// System directory separator
string sep;

string read_text_file(string filepath)
{
    ifstream in_file(filepath);

    if (!in_file.is_open())
    {
        FATAL_ERROR("Cannot open file %s for reading.\n", filepath.c_str());
    }

    string text;

    in_file.seekg(0, std::ios::end);
    text.resize(in_file.tellg());

    in_file.seekg(0, std::ios::beg);
    in_file.read(&text[0], text.size());

    in_file.close();

    return text;
}

void write_text_file(string filepath, string text)
{
    ofstream out_file(filepath, std::ofstream::binary);

    if (!out_file.is_open())
        FATAL_ERROR("Cannot open file %s for writing.\n", filepath.c_str());

    out_file << text;

    out_file.close();
}

string json_to_string(const Json &data, const string &field = "", bool silent = false)
{
    const Json value = !field.empty() ? data[field] : data;
    string output = "";
    switch (value.type())
    {
    case Json::Type::STRING:
        output = value.string_value();
        break;
    case Json::Type::NUMBER:
        output = std::to_string(value.int_value());
        break;
    case Json::Type::BOOL:
        output = value.bool_value() ? "TRUE" : "FALSE";
        break;
    case Json::Type::NUL:
        output = "";
        break;
    default:
    {
        if (!silent)
        {
            string s = !field.empty() ? ("Value for '" + field + "'") : "JSON field";
            FATAL_ERROR("%s is unexpected type; expected string, number, or bool.\n", s.c_str());
        }
    }
    }

    if (!silent && output.empty())
    {
        string s = !field.empty() ? ("Value for '" + field + "'") : "JSON field";
        FATAL_ERROR("%s cannot be empty.\n", s.c_str());
    }

    return output;
}

string generate_map_header_text(Json map_data, Json layouts_data)
{
    string map_layout_id = json_to_string(map_data, "layout");
    string mapName = json_to_string(map_data, "name");

    vector<Json> matched;

    for (auto &layout : layouts_data["layouts"].array_items())
    {
        if (map_layout_id == json_to_string(layout, "id", true))
            matched.push_back(layout);
    }

    if (matched.size() != 1)
        FATAL_ERROR("Failed to find matching layout for %s.\n", map_layout_id.c_str());

    Json layout = matched[0];

    // Extract region from the layout ID (assuming format LAYOUT_HOENN_*)
    string region = "hoenn"; // Default to hoenn
    if (map_layout_id.find("LAYOUT_HOENN_") != string::npos)
    {
        region = "Hoenn";
    }
    else if (map_layout_id.find("LAYOUT_KANTO_") != string::npos)
    {
        region = "Kanto";
    }

    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/" << mapName << "/map.json\n@\n\n";

    text << mapName << ":\n"
         << "\t.4byte " << json_to_string(layout, "name") << "\n";

    if (map_data.object_items().find("shared_events_map") != map_data.object_items().end())
        text << "\t.4byte " << json_to_string(map_data, "shared_events_map") << "_MapEvents\n";
    else
        text << "\t.4byte " << mapName << "_MapEvents\n";

    if (map_data.object_items().find("shared_scripts_map") != map_data.object_items().end())
        text << "\t.4byte " << json_to_string(map_data, "shared_scripts_map") << "_MapScripts\n";
    else
        text << "\t.4byte " << mapName << "_MapScripts\n";

    if (map_data.object_items().find("connections") != map_data.object_items().end() && map_data["connections"].array_items().size() > 0 && json_to_string(map_data, "connections_no_include", true) != "TRUE")
        text << "\t.4byte " << mapName << "_MapConnections\n";
    else
        text << "\t.4byte NULL\n";

    text << "\t.2byte " << json_to_string(map_data, "music") << "\n"
         << "\t.2byte " << json_to_string(layout, "id") << "\n"
         << "\t.byte " << json_to_string(map_data, "region_map_section") << "\n"
         << "\t.byte " << json_to_string(map_data, "requires_flash") << "\n"
         << "\t.byte " << json_to_string(map_data, "weather") << "\n"
         << "\t.byte " << json_to_string(map_data, "map_type") << "\n";

    if (version != "firered")
        text << "\t.2byte 0\n";

    if (version == "ruby")
        text << "\t.byte " << json_to_string(map_data, "show_map_name") << "\n";
    else if (version == "emerald" || version == "firered")
        text << "\tmap_header_flags "
             << "allow_cycling=" << json_to_string(map_data, "allow_cycling") << ", "
             << "allow_escaping=" << json_to_string(map_data, "allow_escaping") << ", "
             << "allow_running=" << json_to_string(map_data, "allow_running") << ", "
             << "show_map_name=" << json_to_string(map_data, "show_map_name") << "\n";

    if (version == "firered")
        text << "\t.byte " << json_to_string(map_data, "floor_number") << "\n";

    text << "\t.byte " << json_to_string(map_data, "battle_scene") << "\n\n";

    return text.str();
}

string generate_map_connections_text(Json map_data)
{
    if (map_data["connections"] == Json())
        return string("\n");

    ostringstream text;

    string mapName = json_to_string(map_data, "name");

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/" << mapName << "/map.json\n@\n\n";

    text << mapName << "_MapConnectionsList:\n";

    for (auto &connection : map_data["connections"].array_items())
    {
        string destMap = json_to_string(connection, "map");
        string region = "HOENN";
        if (destMap.find("MAP_KANTO_") != string::npos)
        {
            region = "KANTO";
        }
        else if (destMap.find("MAP_HOENN_") != string::npos)
        {
            region = "HOENN";
        }

        if (destMap.find("MAP_") != 0)
        {
            destMap = "MAP_" + region + "_" + destMap;
        }

        text << "\tconnection "
             << json_to_string(connection, "direction") << ", "
             << json_to_string(connection, "offset") << ", "
             << destMap << "\n";
    }

    text << "\n"
         << mapName << "_MapConnections:\n"
         << "\t.4byte " << map_data["connections"].array_items().size() << "\n"
         << "\t.4byte " << mapName << "_MapConnectionsList\n\n";

    return text.str();
}

string generate_map_events_text(Json map_data)
{
    if (map_data.object_items().find("shared_events_map") != map_data.object_items().end())
        return string("\n");

    ostringstream text;

    string mapName = json_to_string(map_data, "name");

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/" << mapName << "/map.json\n@\n\n\t.align 2\n\n";

    string objects_label, warps_label, coords_label, bgs_label;

    if (map_data["object_events"].array_items().size() > 0)
    {
        objects_label = mapName + "_ObjectEvents";
        text << objects_label << ":\n";
        for (unsigned int i = 0; i < map_data["object_events"].array_items().size(); i++)
        {
            auto obj_event = map_data["object_events"].array_items()[i];
            string type = json_to_string(obj_event, "type", true);
            string targetMap = json_to_string(obj_event, "target_map", true);

            string region = "";
            if (mapName.find("HOENN_") != string::npos)
            {
                region = "HOENN_";
            }
            else if (mapName.find("KANTO_") != string::npos)
            {
                region = "KANTO_";
            }

            if (!targetMap.empty() && targetMap.find("MAP_HOENN_") == string::npos &&
                targetMap.find("MAP_KANTO_") == string::npos && targetMap.find("MAP_") == 0)
            {
                targetMap = "MAP_" + region + targetMap.substr(4);
            }

            // If no type field is present, assume it's a regular object event.
            if (type == "" || type == "object")
            {
                text << "\tobject_event " << i + 1 << ", "
                     << json_to_string(obj_event, "graphics_id") << ", "
                     << json_to_string(obj_event, "x") << ", "
                     << json_to_string(obj_event, "y") << ", "
                     << json_to_string(obj_event, "elevation") << ", "
                     << json_to_string(obj_event, "movement_type") << ", "
                     << json_to_string(obj_event, "movement_range_x") << ", "
                     << json_to_string(obj_event, "movement_range_y") << ", "
                     << json_to_string(obj_event, "trainer_type") << ", "
                     << json_to_string(obj_event, "trainer_sight_or_berry_tree_id") << ", "
                     << json_to_string(obj_event, "script") << ", "
                     << json_to_string(obj_event, "flag") << "\n";
            }
            else if (type == "clone")
            {
                text << "\tclone_event " << i + 1 << ", "
                     << json_to_string(obj_event, "graphics_id") << ", "
                     << json_to_string(obj_event, "x") << ", "
                     << json_to_string(obj_event, "y") << ", "
                     << json_to_string(obj_event, "target_local_id") << ", "
                     << targetMap << "\n";
            }
            else
            {
                FATAL_ERROR("Unknown object event type '%s'. Expected 'object' or 'clone'.\n", type.c_str());
            }
        }
        text << "\n";
    }
    else
    {
        objects_label = "NULL";
    }

    if (map_data["warp_events"].array_items().size() > 0)
    {
        warps_label = mapName + "_MapWarps";
        text << warps_label << ":\n";
        for (auto &warp_event : map_data["warp_events"].array_items())
        {
            text << "\twarp_def "
                 << json_to_string(warp_event, "x") << ", "
                 << json_to_string(warp_event, "y") << ", "
                 << json_to_string(warp_event, "elevation") << ", "
                 << json_to_string(warp_event, "dest_warp_id") << ", "
                 << json_to_string(warp_event, "dest_map") << "\n";
        }
        text << "\n";
    }
    else
    {
        warps_label = "NULL";
    }

    if (map_data["coord_events"].array_items().size() > 0)
    {
        coords_label = mapName + "_MapCoordEvents";
        text << coords_label << ":\n";
        for (auto &coord_event : map_data["coord_events"].array_items())
        {
            string type = json_to_string(coord_event, "type");
            if (type == "trigger")
            {
                text << "\tcoord_event "
                     << json_to_string(coord_event, "x") << ", "
                     << json_to_string(coord_event, "y") << ", "
                     << json_to_string(coord_event, "elevation") << ", "
                     << json_to_string(coord_event, "var") << ", "
                     << json_to_string(coord_event, "var_value") << ", "
                     << json_to_string(coord_event, "script") << "\n";
            }
            else if (type == "weather")
            {
                text << "\tcoord_weather_event "
                     << json_to_string(coord_event, "x") << ", "
                     << json_to_string(coord_event, "y") << ", "
                     << json_to_string(coord_event, "elevation") << ", "
                     << json_to_string(coord_event, "weather") << "\n";
            }
            else
            {
                FATAL_ERROR("Unknown coord event type '%s'. Expected 'trigger' or 'weather'.\n", type.c_str());
            }
        }
        text << "\n";
    }
    else
    {
        coords_label = "NULL";
    }

    if (map_data["bg_events"].array_items().size() > 0)
    {
        bgs_label = mapName + "_MapBGEvents";
        text << bgs_label << ":\n";
        for (auto &bg_event : map_data["bg_events"].array_items())
        {
            string type = json_to_string(bg_event, "type");
            if (type == "sign")
            {
                text << "\tbg_sign_event "
                     << json_to_string(bg_event, "x") << ", "
                     << json_to_string(bg_event, "y") << ", "
                     << json_to_string(bg_event, "elevation") << ", "
                     << json_to_string(bg_event, "player_facing_dir") << ", "
                     << json_to_string(bg_event, "script") << "\n";
            }
            else if (type == "hidden_item")
            {
                text << "\tbg_hidden_item_event "
                     << json_to_string(bg_event, "x") << ", "
                     << json_to_string(bg_event, "y") << ", "
                     << json_to_string(bg_event, "elevation") << ", "
                     << json_to_string(bg_event, "item") << ", "
                     << json_to_string(bg_event, "flag");
                if (version == "firered")
                {
                    text << ", "
                         << json_to_string(bg_event, "quantity") << ", "
                         << json_to_string(bg_event, "underfoot");
                }
                text << "\n";
            }
            else if (type == "secret_base")
            {
                text << "\tbg_secret_base_event "
                     << json_to_string(bg_event, "x") << ", "
                     << json_to_string(bg_event, "y") << ", "
                     << json_to_string(bg_event, "elevation") << ", "
                     << json_to_string(bg_event, "secret_base_id") << "\n";
            }
            else
            {
                FATAL_ERROR("Unknown bg event type '%s'. Expected 'sign', 'hidden_item', or 'secret_base'.\n", type.c_str());
            }
        }
        text << "\n";
    }
    else
    {
        bgs_label = "NULL";
    }

    text << mapName << "_MapEvents::\n"
         << "\tmap_events " << objects_label << ", " << warps_label << ", "
         << coords_label << ", " << bgs_label << "\n\n";

    return text.str();
}

string strip_trailing_separator(string filename)
{
    if (filename.back() == '/' || filename.back() == '\\')
        filename.pop_back();

    return filename;
}
void infer_separator(string filename)
{
    size_t dir_pos = filename.find_last_of("/\\");
    sep = filename[dir_pos];
}
string file_parent(string filename)
{
    size_t dir_pos = filename.find_last_of("/\\");
    return filename.substr(0, dir_pos + 1);
}

void process_map(string map_filepath, string layouts_filepath, string output_dir)
{
    string mapdata_err, layouts_err;

    // Extract region from filepath
    size_t maps_pos = map_filepath.find("maps/");
    size_t region_start = maps_pos + 5; // length of "maps/"
    size_t region_end = map_filepath.find("/", region_start);
    string region = map_filepath.substr(region_start, region_end - region_start);

    string mapdata_json_text = read_text_file(map_filepath);
    string layouts_json_text = read_text_file(layouts_filepath);

    Json map_data = Json::parse(mapdata_json_text, mapdata_err);
    if (map_data == Json())
        FATAL_ERROR("%s\n", mapdata_err.c_str());

    Json layouts_data = Json::parse(layouts_json_text, layouts_err);
    if (layouts_data == Json())
        FATAL_ERROR("%s\n", layouts_err.c_str());

    string header_text = generate_map_header_text(map_data, layouts_data);
    string events_text = generate_map_events_text(map_data);
    string connections_text = generate_map_connections_text(map_data);

    string out_dir = strip_trailing_separator(output_dir).append(sep);
    write_text_file(out_dir + "header.inc", header_text);
    write_text_file(out_dir + "events.inc", events_text);
    write_text_file(out_dir + "connections.inc", connections_text);
}

string generate_groups_text(Json groups_data)
{
    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n@\n\n";

    for (auto &key : groups_data["group_order"].array_items())
    {
        string group = json_to_string(key);
        text << group << "::\n";
        auto maps = groups_data[group].array_items();
        for (Json &map_name : maps)
            text << "\t.4byte " << json_to_string(map_name) << "\n";
        text << "\n";
    }

    text << "\t.align 2\n"
         << "gMapGroups::\n";
    for (auto &group : groups_data["group_order"].array_items())
        text << "\t.4byte " << json_to_string(group) << "\n";
    text << "\n";

    return text.str();
}

string generate_connections_text(Json groups_data, string include_path)
{
    // Structure to store a map's name along with its region.
    struct MapEntry
    {
        string map_name;
        string region;
    };
    vector<MapEntry> map_entries;

    // Iterate over each group in order.
    for (auto &group : groups_data["group_order"].array_items())
    {
        string group_str = json_to_string(group);
        // Determine the region based on the group name.
        string region = "Hoenn"; // Default region.
        if (group_str.find("Kanto_") != string::npos)
            region = "Kanto";
        else if (group_str.find("Hoenn_") != string::npos)
            region = "Hoenn";

        // Add each map from this group, along with its region.
        for (auto &map_obj : groups_data[group_str].array_items())
        {
            string map_name = json_to_string(map_obj);
            map_entries.push_back({map_name, region});
        }
    }

    // If connections_include_order is defined, use it to sort the map entries.
    vector<Json> connections_include_order = groups_data["connections_include_order"].array_items();
    if (!connections_include_order.empty())
    {
        // Helper lambda that returns the index of the map name in the include order.
        auto get_index = [&](const string &name) -> size_t
        {
            for (size_t i = 0; i < connections_include_order.size(); i++)
            {
                if (json_to_string(connections_include_order[i]) == name)
                    return i;
            }
            return connections_include_order.size() + 1000; // A big number if not found.
        };

        sort(map_entries.begin(), map_entries.end(), [&](const MapEntry &a, const MapEntry &b)
             { return get_index(a.map_name) < get_index(b.map_name); });
    }

    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n@\n\n";

    // Output the include statement with region folder.
    for (const auto &entry : map_entries)
        text << "\t.include \"" << include_path << "/" << entry.region << "/" << entry.region << "_" << entry.map_name << "/connections.inc\"\n";

    return text.str();
}

string generate_headers_text(Json groups_data, string include_path)
{
    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n@\n\n";

    // Loop over each group in order.
    for (auto &group : groups_data["group_order"].array_items())
    {
        string group_str = json_to_string(group);
        // Determine region based on the group name.
        string region = "hoenn"; // Default
        if (group_str.find("Kanto_") != string::npos)
            region = "Kanto";
        else if (group_str.find("Hoenn_") != string::npos)
            region = "Hoenn";

        // Now iterate over each map in the current group.
        for (auto map_obj : groups_data[group_str].array_items())
        {
            string map_name = json_to_string(map_obj);
            // Include header file using the region folder.
            text << "\t.include \"" << include_path << "/" << region << "/" << region << "_" << map_name << "/header.inc\"\n";
        }
    }

    return text.str();
}

string generate_events_text(Json groups_data, string include_path)
{
    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from " << include_path << "/map_groups.json\n@\n\n";

    // Iterate through each group in order.
    for (auto &group : groups_data["group_order"].array_items())
    {
        string group_str = json_to_string(group);
        // Determine the region based on the group name.
        string region = "hoenn"; // Default region.
        if (group_str.find("Kanto_") != string::npos)
            region = "Kanto";
        else if (group_str.find("Hoenn_") != string::npos)
            region = "Hoenn";

        // Iterate over each map for the current group.
        for (auto &map_obj : groups_data[group_str].array_items())
        {
            string map_name = json_to_string(map_obj);
            text << "\t.include \"" << include_path << "/" << region << "/" << region << "_" << map_name << "/events.inc\"\n";
        }
    }

    return text.str();
}

string generate_map_constants_text(string groups_filepath, Json groups_data)
{
    string file_dir = strip_trailing_separator(file_parent(groups_filepath));

    ostringstream text;

    text << "#ifndef GUARD_CONSTANTS_MAP_GROUPS_H\n"
         << "#define GUARD_CONSTANTS_MAP_GROUPS_H\n\n";

    text << "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n//\n\n";

    int group_num = 0;

    for (auto &group : groups_data["group_order"].array_items())
    {
        string groupName = json_to_string(group);
        text << "// " << groupName << "\n";
        vector<string> map_ids;
        size_t max_length = 0;

        // Extract region from group name
        string region = "hoenn"; // Default to hoenn
        if (groupName.find("Hoenn_") != string::npos)
        {
            region = "Hoenn";
        }
        else if (groupName.find("Kanto_") != string::npos)
        {
            region = "Kanto";
        }

        for (auto &map_name : groups_data[groupName].array_items())
        {
            string map_str = json_to_string(map_name);
            string map_filepath = file_dir + sep + region + sep + region + "_" + map_str + sep + "map.json";

            string err_str;
            Json map_data = Json::parse(read_text_file(map_filepath), err_str);
            if (map_data == Json())
                FATAL_ERROR("%s: %s\n", map_filepath.c_str(), err_str.c_str());
            string id = json_to_string(map_data, "id", true);
            map_ids.push_back(id);
            if (id.length() > max_length)
                max_length = id.length();
        }

        int map_id_num = 0;
        for (string map_id : map_ids)
        {
            text << "#define " << map_id << string((max_length - map_id.length() + 1), ' ')
                 << "(" << map_id_num++ << " | (" << group_num << " << 8))\n";
        }
        text << "\n";

        group_num++;
    }

    text << "#define MAP_HOENN_GROUPS_COUNT " << group_num << "\n\n";
    text << "#endif // GUARD_CONSTANTS_MAP_GROUPS_H\n";

    return text.str();
}

// Output paths are directories with trailing path separators
void process_groups(string groups_filepath, string output_asm, string output_c)
{
    output_asm = strip_trailing_separator(output_asm); // Remove separator if existing.
    output_c = strip_trailing_separator(output_c);

    string err;
    Json groups_data = Json::parse(read_text_file(groups_filepath), err);

    if (groups_data == Json())
        FATAL_ERROR("%s\n", err.c_str());

    // Add region handling based on group names
    for (auto &key : groups_data["group_order"].array_items())
    {
        string group = json_to_string(key);
        string region = "hoenn"; // Default to hoenn
        if (group.find("Hoenn_") != string::npos)
        {
            region = "Hoenn";
        }
        else if (group.find("Kanto_") != string::npos)
        {
            region = "Kanto";
        }

        // When processing maps in this group, modify the paths
        for (auto &map_name : groups_data[group].array_items())
        {
            string map_str = json_to_string(map_name);
            string map_path = region + "/" + region + "_" + map_str + "/map.json";
            string full_path = "data/maps/" + map_path;

            // Verify file exists
            ifstream f(full_path.c_str());
            if (!f.good())
            {
                FATAL_ERROR("Cannot find map file: %s\n", full_path.c_str());
            }
        }
    }

    string groups_text = generate_groups_text(groups_data);
    string connections_text = generate_connections_text(groups_data, output_asm);
    string headers_text = generate_headers_text(groups_data, output_asm);
    string events_text = generate_events_text(groups_data, output_asm);
    string map_header_text = generate_map_constants_text(groups_filepath, groups_data);

    write_text_file(output_asm + sep + "groups.inc", groups_text);
    write_text_file(output_asm + sep + "connections.inc", connections_text);
    write_text_file(output_asm + sep + "headers.inc", headers_text);
    write_text_file(output_asm + sep + "events.inc", events_text);
    write_text_file(output_c + sep + "map_groups.h", map_header_text);
}

string generate_layout_headers_text(Json layouts_data)
{
    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/layouts/layouts.json\n@\n\n";

    for (auto &layout : layouts_data["layouts"].array_items())
    {
        if (layout == Json::object())
            continue;
        string layoutName = json_to_string(layout, "name");
        string border_label = layoutName + "_Border";
        string blockdata_label = layoutName + "_Blockdata";
        text << border_label << "::\n"
             << "\t.incbin \"" << json_to_string(layout, "border_filepath") << "\"\n\n"
             << blockdata_label << "::\n"
             << "\t.incbin \"" << json_to_string(layout, "blockdata_filepath") << "\"\n\n"
             << "\t.align 2\n"
             << layoutName << "::\n"
             << "\t.4byte " << json_to_string(layout, "width") << "\n"
             << "\t.4byte " << json_to_string(layout, "height") << "\n"
             << "\t.4byte " << border_label << "\n"
             << "\t.4byte " << blockdata_label << "\n"
             << "\t.4byte " << json_to_string(layout, "primary_tileset") << "\n"
             << "\t.4byte " << json_to_string(layout, "secondary_tileset") << "\n";
        if (version == "firered")
        {
            text << "\t.byte " << json_to_string(layout, "border_width") << "\n"
                 << "\t.byte " << json_to_string(layout, "border_height") << "\n"
                 << "\t.2byte 0\n";
        }
        text << "\n";
    }

    return text.str();
}

string generate_layouts_table_text(Json layouts_data)
{
    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/layouts/layouts.json\n@\n\n";

    text << "\t.align 2\n"
         << json_to_string(layouts_data, "layouts_table_label") << "::\n";

    for (auto &layout : layouts_data["layouts"].array_items())
    {
        string layout_name = json_to_string(layout, "name", true);
        if (layout_name.empty())
            layout_name = "NULL";
        text << "\t.4byte " << layout_name << "\n";
    }

    return text.str();
}

string generate_layouts_constants_text(Json layouts_data)
{
    ostringstream text;

    text << "#ifndef GUARD_CONSTANTS_LAYOUTS_H\n"
         << "#define GUARD_CONSTANTS_LAYOUTS_H\n\n";

    text << "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from data/layouts/layouts.json\n//\n\n";

    int i = 1;
    for (auto &layout : layouts_data["layouts"].array_items())
    {
        if (layout != Json::object())
            text << "#define " << json_to_string(layout, "id") << " " << i << "\n";
        i++;
    }

    text << "\n#endif // GUARD_CONSTANTS_LAYOUTS_H\n";

    return text.str();
}

void process_layouts(string layouts_filepath, string output_asm, string output_c)
{
    output_asm = strip_trailing_separator(output_asm).append(sep);
    output_c = strip_trailing_separator(output_c).append(sep);

    string err;
    Json layouts_data = Json::parse(read_text_file(layouts_filepath), err);

    if (layouts_data == Json())
        FATAL_ERROR("%s\n", err.c_str());

    string layout_headers_text = generate_layout_headers_text(layouts_data);
    string layouts_table_text = generate_layouts_table_text(layouts_data);
    string layouts_constants_text = generate_layouts_constants_text(layouts_data);

    write_text_file(output_asm + "layouts.inc", layout_headers_text);
    write_text_file(output_asm + "layouts_table.inc", layouts_table_text);
    write_text_file(output_c + "layouts.h", layouts_constants_text);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        FATAL_ERROR("USAGE: mapjson <mode> <game-version> [options]\n");

    char *version_arg = argv[2];
    version = string(version_arg);
    if (version != "emerald" && version != "ruby" && version != "firered")
        FATAL_ERROR("ERROR: <game-version> must be 'emerald', 'firered', or 'ruby'.\n");

    char *mode_arg = argv[1];
    string mode(mode_arg);
    if (mode != "layouts" && mode != "map" && mode != "groups")
        FATAL_ERROR("ERROR: <mode> must be 'layouts', 'map', or 'groups'.\n");

    if (mode == "map")
    {
        if (argc != 6)
            FATAL_ERROR("USAGE: mapjson map <game-version> <map_file> <layouts_file> <output_dir>\n");

        infer_separator(argv[3]);
        string filepath(argv[3]);
        string layouts_filepath(argv[4]);
        string output_dir(argv[5]);

        process_map(filepath, layouts_filepath, output_dir);
    }
    else if (mode == "groups")
    {
        if (argc != 6)
            FATAL_ERROR("USAGE: mapjson groups <game-version> <groups_file> <output_asm_dir> <output_c_dir>\n");

        infer_separator(argv[3]);
        string filepath(argv[3]);
        string output_asm(argv[4]);
        string output_c(argv[5]);

        process_groups(filepath, output_asm, output_c);
    }
    else if (mode == "layouts")
    {
        if (argc != 6)
            FATAL_ERROR("USAGE: mapjson layouts <game-version> <layouts_file> <output_asm_dir> <output_c_dir>\n");

        infer_separator(argv[3]);
        string filepath(argv[3]);
        string output_asm(argv[4]);
        string output_c(argv[5]);

        process_layouts(filepath, output_asm, output_c);
    }
    else
    {
        FATAL_ERROR("ERROR: <mode> must be 'layouts', 'map', or 'groups'.\n");
    }

    return 0;
}
