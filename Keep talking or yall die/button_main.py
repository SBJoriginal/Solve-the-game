from Button_fonctions import *
game = True
while game == True:
    button_couleur = button_coulour_fonction()
    button_name = choosing_names_fonction()

    if button_couleur == "blue" and button_name == "abort":
        holding_button_fonction(choosing_strips_fonction())

    bomb_batteries = choosing_batteries_fonction()

    if bomb_batteries > 1 and button_name == "detonate":
        print("\n***PRESS AND IMMEDIATELY RELEASE THE BUTTON***")

    label_name = choosing_label_fonction()

    if button_couleur == "white" and label_name == "CAR":
        holding_button_fonction(choosing_strips_fonction())

    if bomb_batteries > 2 and label_name == "FRK":
        print("\n***PRESS AND IMMEDIATELY RELEASE THE BUTTON***")

    if button_couleur == "yellow":
        holding_button_fonction(choosing_strips_fonction())

    if button_couleur == "red" and button_name == "hold":
        print("\n***PRESS AND IMMEDIATELY RELEASE THE BUTTON***")
    else:
        holding_button_fonction(choosing_strips_fonction())
    if game == True:
        choosing_play_again = True
        while choosing_play_again:
            play_agin = input("\nWould you like to play again? ")
            if play_agin == "Y" or play_again == "YES":
                
            if play_agin == "N" or play_again == "NO":
                game = False
                print("\nThank you for playing. going back to the menu!")




pass