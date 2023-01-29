from Wires import wires
from Passwords import passwords

game_list = "1. Wires (W)\n" \
            "2. Passwords (PW)\n" \
            " "
print("\nWELCOME TO THE MAIN MENU!\n")
print("\n'Leave' to quit the simulation\n")
while True:
    game_mode = input("\nWrite the name of the game you wish to play ('menu' to see all games): ")

    if game_mode.upper() == "WIRES" or game_mode.upper() == "WIRE" or game_mode.upper() == "W":
        wires()
    if game_mode.upper() == "PASSWORDS" or game_mode.upper() == "PASSWORD" or game_mode.upper() == "PW":
        passwords()

    if game_mode.upper() == "MENU":
        print(game_list)

    if game_mode.upper() == "LEAVE":
        print("\nHave a wonderful day!")
        break
