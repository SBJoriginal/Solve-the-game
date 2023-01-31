from Wires import wires
from Passwords import passwords
import sys

sys.path.insert(1,
                '/Users/lenny/PycharmProjects copy/TP2/keep-talking-and-nobody-explodes/Keep talking or yall die/Buttons')
from button_main import buttons

welcoming = True

game_list = "1. Wires (W)\n" \
            "2. BUTTONS (B)\n" \
            "3. Passwords (P)\n" \
            " "
while True:
    while welcoming:
        print("\n"
              "░██╗░░░░░░░██╗███████╗██╗░░░░░░█████╗░░█████╗░███╗░░░███╗███████╗\n"
              "░██║░░██╗░░██║██╔════╝██║░░░░░██╔══██╗██╔══██╗████╗░████║██╔════╝\n"
              "░╚██╗████╗██╔╝█████╗░░██║░░░░░██║░░╚═╝██║░░██║██╔████╔██║█████╗░░\n"
              "░░████╔═████║░██╔══╝░░██║░░░░░██║░░██╗██║░░██║██║╚██╔╝██║██╔══╝░░\n"
              "░░╚██╔╝░╚██╔╝░███████╗███████╗╚█████╔╝╚█████╔╝██║░╚═╝░██║███████╗\n"
              "░░░╚═╝░░░╚═╝░░╚══════╝╚══════╝░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚══════╝\n"

              "          ████████╗░█████╗░  ████████╗██╗░░██╗███████╗\n"
              "          ╚══██╔══╝██╔══██╗  ╚══██╔══╝██║░░██║██╔════╝\n"
              "          ░░░██║░░░██║░░██║  ░░░██║░░░███████║█████╗░░\n"
              "          ░░░██║░░░██║░░██║  ░░░██║░░░██╔══██║██╔══╝░░\n"
              "          ░░░██║░░░╚█████╔╝  ░░░██║░░░██║░░██║███████╗\n"
              "          ░░░╚═╝░░░░╚════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝\n"

              "                  ██╗░░██╗██╗░░░██╗██████╗░██╗\n"
              "                  ██║░░██║██║░░░██║██╔══██╗██║\n"
              "                  ███████║██║░░░██║██████╦╝██║\n"
              "                  ██╔══██║██║░░░██║██╔══██╗╚═╝\n"
              "                  ██║░░██║╚██████╔╝██████╦╝██╗\n"
              "                  ╚═╝░░╚═╝░╚═════╝░╚═════╝░╚═╝\n"
              )
        print("THIS IS THE MAIN MENU!")
        print("'Leave' to quit the simulation")
        welcoming = False

    game_mode = input("\nWrite the name of the game you wish to play ('menu' to see all games): ")

    if game_mode.upper() == "WIRES" or game_mode.upper() == "WIRE" or game_mode.upper() == "W":
        wires()
        welcoming = True
    if game_mode.upper() == "PASSWORDS" or game_mode.upper() == "PASSWORD" or game_mode.upper() == "PW":
        passwords()
        welcoming = True

    if game_mode.upper() == "BUTTONS" or game_mode.upper() == "BUTTON" or game_mode.upper() == "B":
        buttons()
        welcoming = True

    if game_mode.upper() == "MENU":
        print(game_list)

    if game_mode.upper() == "LEAVE":
        print("\nHave a wonderful day!")
        print("\n"
              "░██████╗░░█████╗░░█████╗░██████╗░██████╗░██╗░░░██╗███████╗\n"
              "██╔════╝░██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗░██╔╝██╔════╝\n"
              "██║░░██╗░██║░░██║██║░░██║██║░░██║██████╦╝░╚████╔╝░█████╗░░\n"
              "██║░░╚██╗██║░░██║██║░░██║██║░░██║██╔══██╗░░╚██╔╝░░██╔══╝░░\n"
              "╚██████╔╝╚█████╔╝╚█████╔╝██████╔╝██████╦╝░░░██║░░░███████╗\n"
              "░╚═════╝░░╚════╝░░╚════╝░╚═════╝░╚═════╝░░░░╚═╝░░░╚══════╝\n"
              )
        break
