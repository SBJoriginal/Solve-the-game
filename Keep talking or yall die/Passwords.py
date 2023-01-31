def passwords():
    possible_passwords = ['about', 'after', 'again', 'below', 'could', 'every', 'first', 'found', 'great',
                          'house', 'large', 'learn', 'never', 'other', 'place', 'plant', 'point', 'right',
                          'small', 'sound', 'spell', 'still', 'study', 'their', 'there', 'these', 'thing',
                          'think', 'three', 'water', 'where', 'which', 'world', 'would', 'write']

    game = True

    all = True
    print("\nWELCOME TO PASSWORDS!\n")
    while game:

        choose = True
        list_choosing = True
        maybe_finish_selector = True
        change_small = True

        while all:
            first_row = []
            a = input("\nFirst letters in the row: ")
            first_row += a.lower()
            second_row = []
            b = input("\nSecond letters in the row: ")
            second_row += b.lower()
            third_row = []
            c = input("\nThird letters in the row: ")
            third_row += c.lower()
            fourth_row = []
            d = input("\nFourth letters in the row: ")
            fourth_row += d.lower()
            fifth_row = []
            e = input("\nFifth letters in the row: ")
            fifth_row += e.lower()
            all = False

        letters = ''
        number_of_letters = ''
        for i in possible_passwords:
            if i[0] in first_row or first_row == []:
                if i[1] in second_row or second_row == []:
                    if i[2] in third_row or third_row == []:
                        if i[3] in fourth_row or fourth_row == []:
                            if i[4] in fifth_row or fifth_row == []:
                                letters += i.upper()
                                number_of_letters += i
                                if (len(number_of_letters) % 5) == 0:
                                    letters += ", "

        if letters == '':
            print("\nTHERE ARE NO MATCHING WORDS! PLEASE REVISE YOUR LETTERS!....bitch")
        else:
            letters = letters[0:(len(letters) - 2)]
            letters += '.'
            print("\nThe answer is :  ", letters)

        while list_choosing:
            see_list = input("\nDo you want to see the lists: ")
            if see_list.upper() == "Y" or see_list.upper() == 'YES':
                print("\nFirst_row = ", first_row)
                print("\nSecond_row = ", second_row)
                print("\nThird_row = ", third_row)
                print("\nFourth_row = ", fourth_row)
                print("\nFifth_row = ", fifth_row)
                choose = True
                list_choosing = False

            if see_list.upper() == "N" or see_list.upper() == 'NO':
                game = False
                choose = False
                changing = False
                list_choosing = False

        while choose:
            change = input("\nDo you want to change one of the lists: ")
            if change.upper() == 'Y' or change.upper() == 'YES':
                changing = True
                change_small = True
                choose = False
            if change.upper() == 'N' or change.upper() == 'NO':
                game = False
                choose = False
                changing = False

        while changing:
            while change_small:
                change = input('\nPut number of list you want to change ("all" for all of them): ')
                if change == "1":
                    first_row = []
                    a = input("\nFirst letters in the row: ")
                    first_row += a.lower()
                    maybe_finish_selector = True
                    change_small = False
                if change == "2":
                    second_row = []
                    b = input("\nSecond letters in the row: ")
                    second_row += b.lower()
                    maybe_finish_selector = True
                    change_small = False
                if change == "3":
                    third_row = []
                    c = input("\nThird letters in the row: ")
                    third_row += c.lower()
                    maybe_finish_selector = True
                    change_small = False
                if change == "4":
                    fourth_row = []
                    d = input("\nFourth letters in the row: ")
                    fourth_row += d.lower()
                    maybe_finish_selector = True
                    change_small = False
                if change == "5":
                    fifth_row = []
                    e = input("\nFifth letters in the row: ")
                    fifth_row += e.lower()
                    maybe_finish_selector = True
                    change_small = False
                if change.upper() == "ALL":
                    all = True
                    changing = False
                    maybe_finish_selector = False
                    change_small = False

            while maybe_finish_selector:
                maybe_finish = input('\nWould you like to change another row? y for yes. n for no.')
                if maybe_finish.upper() == 'Y' or maybe_finish.upper() == 'YES':
                    maybe_finish_selector = False
                    change_small = True
                if maybe_finish.upper() == 'N' or maybe_finish.upper() == 'NO':
                    changing = False
                    maybe_finish_selector = False
                    change_small = False

    print("\nThank you for playing. going back to the menu!\n")
