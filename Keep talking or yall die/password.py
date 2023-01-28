passwords = ['about', 'after', 'again', 'below', 'could', 'every', 'first', 'found', 'great', 'house', 'large', 'learn',
             'never', 'other', 'place', 'plant', 'point', 'right', 'small', 'sound', 'spell', 'still', 'study', 'their',
             'there', 'these', 'thing', 'think', 'three', 'water', 'where', 'which', 'world', 'would', 'write']

game = True
choose = True
all = True

while game:

    while all:
        first_row = []
        a = input("first letters in the row: ")
        first_row += a
        second_row = []
        b = input("second letters in the row: ")
        second_row += b
        third_row = []
        c = input("third letters in the row: ")
        third_row += c
        fourth_row = []
        d = input("forth letters in the row: ")
        fourth_row += d
        fifth_row = []
        e = input("fifth letters in the row: ")
        fifth_row += e
        all = False

    letters = ''
    number_of_letters = ''
    for i in passwords:
        if i[0] in first_row or first_row == []:
            if i[1] in second_row or second_row == []:
                if i[2] in third_row or third_row == []:
                    if i[3] in fourth_row or fourth_row == []:
                        if i[4] in fifth_row or fifth_row == []:
                            letters += i.upper()
                            number_of_letters += i
                            if (len(number_of_letters) % 5) == 0:
                                letters += ", "

    print("the answer is :  ")

    if letters == []:
        print("THERE ARE NO MATCHING WORDS! PLEASE REVISE YOUR LETTERS!....bitch")
    else:
        letters = letters[0:(len(letters) - 2)]
        letters += '.'
        print(letters)

    see_list = input("do you want to see the lists: ")
    if see_list == "y" or see_list == ' yes':

        print("first_row = ", first_row)
        print("second_row = ", second_row)
        print("third_row = ", third_row)
        print("fourth_row = ", fourth_row)
        print("fifth_row = ", fifth_row)
        choose = True

    else:
        game = False
        choose = False
        changing = False

    while choose:
        change = input("do you want to change one of the lists: ")
        if change == 'y' or change == 'yes':
            changing = True
            choose = False
        else:
            game = False
            choose = False
            changing = False

    while changing:
        change = input('put number of list you want to change ("all" for all of them): ')
        if change == "1":
            first_row = []
            a = input("first letters in the row: ")
            first_row += a
            maybe_finish_selector = True
        if change == "2":
            second_row = []
            b = input("second letters in the row: ")
            second_row += b
            maybe_finish_selector = True
        if change == "3":
            third_row = []
            c = input("third letters in the row: ")
            third_row += c
            maybe_finish_selector = True
        if change == "4":
            fourth_row = []
            d = input("forth letters in the row: ")
            fourth_row += d
            maybe_finish_selector = True
        if change == "5":
            fifth_row = []
            e = input("fifth letters in the row: ")
            fifth_row += e
            maybe_finish_selector = True
        if change == "all":
            all = True
            changing = False
            maybe_finish_selector = False

        while maybe_finish_selector:
            maybe_finish = input('would you like to change another row? y for yes. n for no.')
            if maybe_finish == 'y':
                maybe_finish_selector = False
            else:
                changing = False
                maybe_finish_selector = False

print('Thank you for playing!')
