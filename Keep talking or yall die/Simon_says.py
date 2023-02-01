def simon_says():
    standard = ['red','blue','yellow','green']
    has_no_strikes_with_vowel = {"red":"blue", "blue":"red", "green":"yellow", "yellow":"green"}
    has_one_strikes_with_vowel = {"red":"yellow", "blue":"green", "green":"blue", "yellow":"red"}
    has_two_strikes_with_vowel = {"red":"green", "blue":"red", "green":"yellow", "yellow":"blue"}
    has_no_strikes_with_no_vowel = {"red":"blue", "blue":"yellow", "green":"green", "yellow":"red"}
    has_one_strikes_with_no_vowel = {"red":"red", "blue":"blue", "green":"yellow", "yellow":"green"}
    has_two_strikes_with_no_vowel = {"red":"yellow", "blue":"green", "green":"blue", "yellow":"red"}
    end_game = True
    choosing_vowel = True
    list_of_colours = []

    print("\n"
          "█░█░█ █▀▀ █░░ █▀▀ █▀█ █▀▄▀█ █▀▀   ▀█▀ █▀█\n"
          "▀▄▀▄▀ ██▄ █▄▄ █▄▄ █▄█ █░▀░█ ██▄   ░█░ █▄█\n\n"

          "░██████╗██╗███╗░░░███╗░█████╗░███╗░░██╗  ░██████╗░█████╗░██╗░░░██╗░██████╗\n"
          "██╔════╝██║████╗░████║██╔══██╗████╗░██║  ██╔════╝██╔══██╗╚██╗░██╔╝██╔════╝\n"
          "╚█████╗░██║██╔████╔██║██║░░██║██╔██╗██║  ╚█████╗░███████║░╚████╔╝░╚█████╗░\n"
          "░╚═══██╗██║██║╚██╔╝██║██║░░██║██║╚████║  ░╚═══██╗██╔══██║░░╚██╔╝░░░╚═══██╗\n"
          "██████╔╝██║██║░╚═╝░██║╚█████╔╝██║░╚███║  ██████╔╝██║░░██║░░░██║░░░██████╔╝\n"
          "╚═════╝░╚═╝╚═╝░░░░░╚═╝░╚════╝░╚═╝░░╚══╝  ╚═════╝░╚═╝░░╚═╝░░░╚═╝░░░╚═════╝░\n"
          )
    def choosing_strikes_fonction():
        choosing_strikes = True
        while choosing_strikes:
            strikes = input("\nHow many strikes are there? ")#do the while statement
            if strikes == "0" or strikes == "1" or strikes == "2":
                choosing_strikes = False
                return strikes
            else:
                print("Enter either '0', '1' or '2'")





    strikes = choosing_strikes_fonction()


    while end_game == True:

        while choosing_vowel:
            vowel = input("\nDoes the serial number contain a vowel? ")  # do while statement
            if vowel.upper() == "Y" or vowel.upper() == "YES":
                choosing_vowel = False
            if vowel.upper() == "N" or vowel.upper() == "NO":
                choosing_vowel = False



        while len(list_of_colours) != 4 and strikes == "0" and (vowel.upper() == "Y" or vowel.upper() == "YES"):
            choosing_colour = True
            while choosing_colour:
                colours = input("\nWhat is the next flashing light? ")
                if colours in standard:
                    choosing_colour = False
                else:
                    print("\nWrite from the list of colours", standard)
            list_of_colours.append(colours)
            for i in list_of_colours:
                print("\n***Press on ",has_no_strikes_with_vowel[i],"***")
            if len(list_of_colours) != 4:
                strikes = choosing_strikes_fonction()

        while len(list_of_colours) != 4 and strikes == "1" and (vowel.upper() == "Y" or vowel.upper() == "YES"):
            choosing_colour = True
            while choosing_colour:
                colours = input("\nWhat is the next flashing light? ")
                if colours in standard:
                    choosing_colour = False
                else:
                    print("\nWrite from the list of colours", standard)
            list_of_colours.append(colours)
            for i in list_of_colours:
                print("\n***Press on ",has_one_strikes_with_vowel[i],"***")
            if len(list_of_colours) != 4:
                strikes = choosing_strikes_fonction()

        while len(list_of_colours) != 4 and strikes == "2" and (vowel.upper() == "Y" or vowel.upper() == "YES"):
            choosing_colour = True
            while choosing_colour:
                colours = input("\nWhat is the next flashing light? ")
                if colours in standard:
                    choosing_colour = False
                else:
                    print("\nWrite from the list of colours", standard)
            list_of_colours.append(colours)
            for i in list_of_colours:
                print("\n***Press on ",has_two_strikes_with_vowel[i],"***")
            if len(list_of_colours) != 4:
                strikes = choosing_strikes_fonction()

        while len(list_of_colours) != 4 and strikes == "0" and (vowel.upper() == "N" or vowel.upper() == "NO"):
            choosing_colour = True
            while choosing_colour:
                colours = input("\nWhat is the next flashing light? ")
                if colours in standard:
                    choosing_colour = False
                else:
                    print("\nWrite from the list of colours", standard)
            list_of_colours.append(colours)
            for i in list_of_colours:
                print("\n***Press on ",has_no_strikes_with_no_vowel[i],"***")
            if len(list_of_colours) != 4:
                strikes = choosing_strikes_fonction()

        while len(list_of_colours) != 4 and strikes == "1" and (vowel.upper() == "N" or vowel.upper() == "NO"):
            choosing_colour = True
            while choosing_colour:
                colours = input("\nWhat is the next flashing light? ")
                if colours in standard:
                    choosing_colour = False
                else:
                    print("\nWrite from the list of colours", standard)
            list_of_colours.append(colours)
            for i in list_of_colours:
                print("\n***Press on ",has_one_strikes_with_no_vowel[i],"***")
            if len(list_of_colours) != 4:
                strikes = choosing_strikes_fonction()

        while len(list_of_colours) != 4 and strikes == "2" and (vowel.upper() == "N" or vowel.upper() == "NO"):
            choosing_colour = True
            while choosing_colour:
                colours = input("\nWhat is the next flashing light? ")
                if colours in standard:
                    choosing_colour = False
                else:
                    print("\nWrite from the list of colours", standard)
            list_of_colours.append(colours)
            for i in list_of_colours:
                print("\n***Press on ",has_two_strikes_with_no_vowel[i],"***")
            if len(list_of_colours) != 4:
                strikes = choosing_strikes_fonction()

        if len(list_of_colours) == 4:
            play_again = input("\nDo you want to play again? ")
            if play_again.upper() == "Y" or play_again.upper() == "YES":
                list_of_colours = []
            if play_again.upper() == "N" or play_again.upper() == "NO":
                end_game = False

    print("\nThank you for playing. going back to the menu!\n")