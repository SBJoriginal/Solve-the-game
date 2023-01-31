possible_button_colour = ["blue", "red", "white", "yellow", "black"]
possible_strips = ["blue", "red", "white", "yellow"]
possible_names = ["abort", "detonate", "hold", "press"]
possible_labels = ['SND', 'CLR', 'CAR', 'IND', 'FRQ', 'SIG', 'NSA', 'MSA', 'TRN', 'BOB', 'FRK']


def button_coulour_fonction():
    choosing_button_colour = True
    while choosing_button_colour:
        button_colour = input("\nWhat is the color of the button? ")
        button_colour = button_colour.lower()
        if button_colour in possible_button_colour:
            choosing_button_colour = False
        else:
            print("\nEnter a valid colour from the list... ")
            print(possible_button_colour)
    return button_colour


def choosing_names_fonction():
    choosing_names = True
    while choosing_names:
        names = input("\nWhat is the word on the button? ")
        names = names.lower()
        if names in possible_names:
            choosing_names = False
        else:
            print("\nEnter a valid name from the list... ")
            print(possible_names)
    return names


def choosing_strips_fonction():
    choosing_strips = True
    while choosing_strips:
        strip = input("\nWhat is the colour of the strip on the button? ")
        strip = strip.lower()
        if strip in possible_strips:
            choosing_strips = False
        else:
            print("\nEnter a valid colour from the list... ")
            print(possible_strips)
    return strip


def holding_button_fonction(strip):
    holding_button = True
    while holding_button:
        if strip == "blue":
            print("\n***LET GO WHEN TIMER HAS A 4 IN IT***")
            holding_button = False

        if strip == "white":
            print("\n***LET GO WHEN TIMER HAS A 1 IN IT***")
            holding_button = False

        if strip == "yellow":
            print("\n***LET GO WHEN TIMER HAS A 5 IN IT***")
            holding_button = False

        if strip == "red":
            print("\n***LET GO WHEN TIMER HAS A 1 IN IT***")
            holding_button = False


def choosing_batteries_fonction():
    choosing_batteries = True
    while choosing_batteries:
        batteries = input("\nHow many batteries on the bomb? ")
        try:
            batteries = int(batteries)
            choosing_batteries = False
        except:
            print("\nEnter a number please..")
    return batteries


def choosing_label_fonction():
    choosing_label = True
    while choosing_label:
        labels = input("\nName of a label on the bomb? ")
        labels = labels.upper()
        if labels in possible_labels:
            choosing_label = False
        else:
            print("\nEnter a valid label from the list... ")
            print(possible_labels)
    return labels

# button_coulour_fonction()
# # choosing_names_fonction()
# choosing_strips_fonction()
# # holding_button_fonction(choosing_strips_fonction())
# choosing_batteries_fonction()
# choosing_label_fonction()
