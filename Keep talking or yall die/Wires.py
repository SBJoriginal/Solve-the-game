def wires():
    print("\nWELCOME TO WIRES!\n")
    playing_wires = True
    while playing_wires:  # INDENT EVERYTHING WHEN READY
        # 3
        choosing_wire_quantity = True
        choosing_red = True
        choosing_last_wire_white = True
        choosing_more_then_one_blue_wire = True
        # 4
        choosing_more_then_one_red_wire = True
        choosing_odd_serial_number = True
        choosing_last_wire_yellow = True
        choosing_more_then_one_red_wire_2 = True
        choosing_one_blue_wire = True
        choosing_more_then_one_yellow_wire = True
        # 5
        choosing_last_wire_black = True
        choosing_odd_serial_number_2 = True
        choosing_one_red_wire = True
        choosing_more_then_one_yellow_wire_2 = True
        choosing_no_black_wires = True

        # 6
        choosing_no_yellow_wires = True
        choosing_odd_serial_number_3 = True
        choosing_one_yellow_wire = True
        choosing_more_then_one_white_wire = True
        choosing_no_red_wires_2 = True

        # end game
        choosing_play_again = True

        while choosing_wire_quantity:
            try:
                wire_quantity = input('\nHow many wires do you have: ')
                wire_quantity = int(wire_quantity)
                choosing_wire_quantity = False
            except:
                print('Give me a number')

        if wire_quantity == 3:

            while choosing_red:
                red = input("\nRed wires? ")
                if red.upper() == 'N' or red.upper() == 'NO':
                    print('\n*****CUT THE SECOND WIRE!*****\n')
                    choosing_red = False
                    choosing_last_wire_white = False
                    choosing_more_then_one_blue_wire = False

                if red.upper() == 'Y' or red.upper() == 'YES':
                    choosing_red = False

            while choosing_last_wire_white:
                last_wire_white = input("\nIs the last wire white? ")
                if last_wire_white.upper() == 'Y' or last_wire_white.upper() == 'YES':
                    print('\n*****CUT THE LAST WIRE!*****\n')
                    choosing_last_wire_white = False
                    choosing_more_then_one_blue_wire = False
                if last_wire_white.upper() == 'N' or last_wire_white.upper() == 'NO':
                    choosing_last_wire_white = False

            while choosing_more_then_one_blue_wire:
                more_then_one_blue_wire = input("\nIs there more then one blue wire? ")
                if more_then_one_blue_wire.upper() == 'Y' or more_then_one_blue_wire.upper() == 'YES':
                    print('\n*****CUT THE LAST BLUE WIRE!*****\n')
                    choosing_more_then_one_blue_wire = False
                if more_then_one_blue_wire.upper() == 'N' or more_then_one_blue_wire.upper() == 'NO':
                    print('\n*****CUT THE LAST WIRE!*****\n')
                    choosing_more_then_one_blue_wire = False

        if wire_quantity == 4:
            while choosing_more_then_one_red_wire and choosing_odd_serial_number == True:
                more_then_one_red_wire = input("\nIs there more then one red wire?('0' if there are none)  ")

                if more_then_one_red_wire.upper() == "Y" or more_then_one_red_wire.upper() == "YES":

                    odd_serial_number = input("\nLast digit of the serial number is odd? ")

                    if odd_serial_number.upper() == "Y" or odd_serial_number.upper() == "YES":
                        print('\n*****CUT THE LAST RED WIRE!*****\n')
                        choosing_more_then_one_red_wire = False
                        choosing_odd_serial_number = False
                        choosing_more_then_one_red_wire_2 = False
                        choosing_last_wire_yellow = False
                        choosing_one_blue_wire = False
                        choosing_more_then_one_yellow_wire = False

                    if odd_serial_number.upper() == "N" or odd_serial_number.upper() == "NO":
                        choosing_odd_serial_number = False

                if more_then_one_red_wire.upper() == "N" or more_then_one_red_wire.upper() == "NO":
                    choosing_more_then_one_red_wire = False

                if more_then_one_red_wire == "0":
                    choosing_more_then_one_red_wire = False

            while choosing_last_wire_yellow and choosing_more_then_one_red_wire_2 == True:
                last_wire_yellow = input("\nIs the last wire yellow ? ")
                if last_wire_yellow.upper() == "Y" or last_wire_yellow.upper() == "YES":
                    if more_then_one_red_wire == "0":
                        print('\n*****CUT THE FIRST WIRE!*****\n')
                        choosing_more_then_one_red_wire_2 = False
                        choosing_last_wire_yellow = False
                        choosing_one_blue_wire = False
                        choosing_more_then_one_yellow_wire = False

                    if more_then_one_red_wire != "0":
                        choosing_more_then_one_red_wire_2 = False
                if last_wire_yellow.upper() == "N" or last_wire_yellow.upper() == "NO":
                    choosing_last_wire_yellow = False

            while choosing_one_blue_wire:
                one_blue_wire = input("\nIs there exactly one blue wire? ")
                if one_blue_wire.upper() == "Y" or one_blue_wire.upper() == "YES":
                    print('\n*****CUT THE FIRST WIRE!*****\n')
                    choosing_one_blue_wire = False
                    choosing_more_then_one_yellow_wire = False
                if one_blue_wire.upper() == "N" or one_blue_wire.upper() == "NO":
                    choosing_one_blue_wire = False

            while choosing_more_then_one_yellow_wire:
                more_then_one_yellow_wire = input("\nMore the one yellow wire? ")
                if more_then_one_yellow_wire.upper() == "Y" or more_then_one_yellow_wire.upper() == "YES":
                    print('\n*****CUT THE LAST WIRE!*****\n')
                    choosing_more_then_one_yellow_wire = False
                if more_then_one_yellow_wire.upper() == "N" or more_then_one_yellow_wire.upper() == "NO":
                    print('\n*****CUT THE SECOND WIRE!*****\n')
                    choosing_more_then_one_yellow_wire = False

        if wire_quantity == 5:

            while choosing_last_wire_black and choosing_odd_serial_number_2:
                last_wire_black = input("\nLast wire black? ('0' if there are none) ")
                if last_wire_black.upper() == "Y" or last_wire_black.upper() == "YES":
                    odd_serial_number_2 = input("\nIs last digit of serial code odd? ")
                    if odd_serial_number_2.upper() == "Y" or odd_serial_number_2.upper() == "YES":
                        print('\n*****CUT THE FOURTH WIRE!*****\n')
                        choosing_last_wire_black = False
                        choosing_odd_serial_number_2 = False
                        choosing_one_red_wire = False
                        choosing_more_then_one_yellow_wire_2 = False
                        choosing_no_black_wires = False
                    if odd_serial_number_2.upper() == "N" or odd_serial_number_2.upper() == "NO":
                        choosing_odd_serial_number_2 = False
                if last_wire_black.upper() == "N" or last_wire_black.upper() == "NO":
                    choosing_last_wire_black = False
                if last_wire_black == "0":
                    choosing_last_wire_black = False

            while choosing_one_red_wire and choosing_more_then_one_yellow_wire_2:
                one_red_wire = input("\nExactly one red wire? ")
                if one_red_wire.upper() == "Y" or one_red_wire.upper() == "YES":
                    more_then_one_yellow_wire_2 = input("\nMore then one yellow wire? ")
                    if more_then_one_yellow_wire_2.upper() == "Y" or more_then_one_yellow_wire_2.upper() == "YES":
                        print('\n*****CUT THE FIRST WIRE!*****\n')
                        choosing_one_red_wire = False
                        choosing_more_then_one_yellow_wire_2 = False
                        choosing_no_black_wires = False
                    if more_then_one_yellow_wire_2.upper() == "N" or more_then_one_yellow_wire_2.upper() == "NO":
                        choosing_more_then_one_yellow_wire_2 = False
                if one_red_wire.upper() == "N" or one_red_wire.upper() == "NO":
                    choosing_one_red_wire = False

            while choosing_no_black_wires:
                if last_wire_black == "0":
                    print('\n*****CUT THE SECOND WIRE!*****\n')
                    choosing_no_black_wires = False
                if last_wire_black != "0":
                    print('\n*****CUT THE FIRST WIRE!*****\n')
                    choosing_no_black_wires = False

        if wire_quantity == 6:

            while choosing_no_yellow_wires and choosing_odd_serial_number_3:
                no_yellow_wires = input("\nAre there yellow wires? (1 if theres exactly one) ")
                if no_yellow_wires.upper() == "N" or no_yellow_wires.upper() == "NO":
                    odd_serial_number_3 = input("\nIs last digit of serial code odd? ")
                    if odd_serial_number_3.upper() == "Y" or odd_serial_number_3.upper() == "YES":
                        print('\n*****CUT THE THIRD WIRE!*****\n')
                        choosing_no_yellow_wires = False
                        choosing_odd_serial_number_3 = False
                        choosing_one_yellow_wire = False
                        choosing_more_then_one_white_wire = False
                        choosing_no_red_wires_2 = False

                    if odd_serial_number_3.upper() == "N" or odd_serial_number_3.upper() == "NO":
                        choosing_odd_serial_number_3 = False
                if no_yellow_wires.upper() == "Y" or no_yellow_wires.upper() == "YES":
                    choosing_no_yellow_wires = False
                if no_yellow_wires == "1":
                    choosing_no_yellow_wires = False

            while choosing_one_yellow_wire and choosing_more_then_one_white_wire:
                if no_yellow_wires == "1":
                    more_then_one_white_wire = input("\n Is there more then one white wire? ")
                    if more_then_one_white_wire.upper() == "Y" or more_then_one_white_wire.upper() == "YES":
                        print('\n*****CUT THE FOURTH WIRE!*****\n')
                        choosing_one_yellow_wire = False
                        choosing_more_then_one_white_wire = False
                        choosing_no_red_wires_2 = False
                    if more_then_one_white_wire.upper() == "N" or more_then_one_white_wire.upper() == "NO":
                        choosing_more_then_one_white_wire = False
                if no_yellow_wires != "1":
                    choosing_one_yellow_wire = False

            while choosing_no_red_wires_2:
                no_red_wires_2 = input("\n Are there any red wires? ")
                if no_red_wires_2.upper() == "N" or no_red_wires_2.upper() == "NO":
                    print('\n*****CUT THE LAST WIRE!*****\n')
                    choosing_no_red_wires_2 = False

                if no_red_wires_2.upper() == "Y" or no_red_wires_2.upper() == "YES":
                    print('\n*****CUT THE FOURTH WIRE!*****\n')
                    choosing_no_red_wires_2 = False

        while choosing_play_again:
            play_again = input("\nDo you want to play again? ")
            if play_again.upper() == "YES" or play_again.upper() == "Y":
                choosing_play_again = False
            if play_again.upper() == "NO" or play_again.upper() == "N":
                choosing_play_again = False
                playing_wires = False

    print("\nThank you for playing. going back to the menu!")
