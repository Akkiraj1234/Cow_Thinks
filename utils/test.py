import random
import sys
import os

message_list = [
    "what i think does not matter beouse sheep just wants to be fucked"
]

cow = [
    "\   ^__^",
    " \  (oo)\_______",
    "    (__)\       )\/\\",
    "         ||----w |",
    "         ||     ||"
]


def formated_cow_think(text:str, cow:list):
    return_text = []
    width, height = os.get_terminal_size()
    
    cow_width = max(map(lambda val: val.__len__(), cow))
    app_width = (width // 4)*3
    app_width = app_width if (app_width + cow_width) <= width else width - cow_width
    
    # if cow_width is less then 0 then we gonna exit the program simple 
    if app_width < 0:
        return f"terminal size is too small expand it to {abs(app_width)}"
    print(app_width, text.__len__(), len(text) // app_width)
    if len(text) >= app_width:
        text_repat = (len(text) // app_width)+1
    else:
        text_repat = 1
        app_width = len(text)
    
    return_text.append(f" /{'-'*(app_width-2)}\\ \n/{' '*app_width}\\")
    range_ = 0
    for _ in range(text_repat):
        print(range_,app_width)
        return_text.append(f"|{text[range_:app_width]}|")
        range_+= app_width
    return_text.append(f"\\{' '*(app_width)}/\n \\{'-'*(app_width-2)}/ ")
    
    return '\n'.join(return_text)

def main():
    print("\x1b[2J\x1b[H\r")
    message = random.choice(message_list)
    text = formated_cow_think(message, cow)
    print(text, flush=True)

if __name__ == "__main__":
    main()