def beautify_json_string(json_string):
    indent_level = 0
    beautified_json = ""
    in_string = False

    for i in range(len(json_string)):
        if json_string[i] == '*' and (i == 0 or json_string[i-1] != '\\'):
            in_string = not in_string
        
        if not in_string:
            if json_string[i] in '{(':
                indent_level += 1
                beautified_json += json_string[i] + "\n" + " " * 4 * indent_level
            elif json_string[i] in '})':
                indent_level -= 1
                beautified_json += "\n" + " " * 4 * indent_level + json_string[i]
            elif json_string[i] == ',':
                beautified_json += json_string[i] + "\n" + " " * 4 * indent_level
            elif json_string[i] == ':':
                beautified_json += json_string[i] + " "
            else:
                beautified_json += json_string[i]
        else:
            beautified_json += json_string[i]

    return beautified_json.strip()

json_string = input()
print(beautify_json_string(json_string))
