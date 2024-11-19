from Buttons.Button_fonctions import *


def buttons():
    game = True
    game_not_over = True
    while game == True:

        print("\n"
              "█░█░█ █▀▀ █░░ █▀▀ █▀█ █▀▄▀█ █▀▀   ▀█▀ █▀█\n"
              "▀▄▀▄▀ ██▄ █▄▄ █▄▄ █▄█ █░▀░█ ██▄   ░█░ █▄█\n\n"

              "██████╗░██╗░░░██╗████████╗████████╗░█████╗░███╗░░██╗░██████╗\n"
              "██╔══██╗██║░░░██║╚══██╔══╝╚══██╔══╝██╔══██╗████╗░██║██╔════╝\n"
              "██████╦╝██║░░░██║░░░██║░░░░░░██║░░░██║░░██║██╔██╗██║╚█████╗░\n"
              "██╔══██╗██║░░░██║░░░██║░░░░░░██║░░░██║░░██║██║╚████║░╚═══██╗\n"
              "██████╦╝╚██████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██║░╚███║██████╔╝\n"
              "╚═════╝░░╚═════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═╝░░╚══╝╚═════╝░\n"
              )
        button_couleur = button_coulour_fonction()
        button_name = choosing_names_fonction()

        if button_couleur == "blue" and button_name == "abort":
            holding_button_fonction(choosing_strips_fonction())
            game_not_over = False

        if game_not_over == True:
            bomb_batteries = choosing_batteries_fonction()

        if game_not_over and bomb_batteries > 1 and button_name == "detonate":
            print("\n***PRESS AND IMMEDIATELY RELEASE THE BUTTON***")
            game_not_over = False

        if game_not_over:
            first_label, second_label = choosing_label_fonction()

        if game_not_over and button_couleur == "white" and (first_label == "CAR" or second_label == "CAR"):
            holding_button_fonction(choosing_strips_fonction())
            game_not_over = False

        if game_not_over and bomb_batteries > 2 and (first_label == "FRK" or second_label == "FRK"):
            print("\n***PRESS AND IMMEDIATELY RELEASE THE BUTTON***")
            game_not_over = False

        if game_not_over and button_couleur == "yellow":
            holding_button_fonction(choosing_strips_fonction())
            game_not_over = False

        if game_not_over and button_couleur == "red" and button_name == "hold":
            print("\n***PRESS AND IMMEDIATELY RELEASE THE BUTTON***")
            game_not_over = False
        else:

            if game_not_over:
                holding_button_fonction(choosing_strips_fonction())

        if game == True:
            choosing_play_again = True
        while choosing_play_again:
            play_again = input("\nWould you like to play again? ")
            if play_again.upper() == "Y" or play_again.upper() == "YES":
                choosing_play_again = False
                game_not_over = True
            if play_again.upper() == "N" or play_again.upper() == "NO":
                choosing_play_again = False
                game = False
                print("\nThank you for playing. going back to the menu!\n")
