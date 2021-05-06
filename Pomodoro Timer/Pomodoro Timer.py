import time
from playsound import playsound

# set a timer and countdown based on length of timer wanted by the user and start it
def countdown(timer_length):
    # countdown until the timer length is 0
    timer_length *= 60
    while timer_length >= 0:
        minute_in_seconds = 60
        minutes, seconds = divmod(timer_length, minute_in_seconds)
        timer = '{:02d}:{:02d}'.format(minutes, seconds)
        print(timer, end="\r")
        time.sleep(1)
        timer_length -= 1

def focus_countdown(interval_length):
    countdown(interval_length)
    # sound from zapsplat.com
    playsound('vibraphone.mp3')

def break_countdown(interval_length):
    countdown(interval_length)
    # sound from zapsplat.com
    playsound('flutter.mp3')

def pomodoro(pomodoro_set, focus_interval, break_interval):
    while pomodoro_set:
        print(f'Pomodoros Left: {pomodoro_set}')
        focus_countdown(focus_interval)
        print('Break Time!')
        break_countdown(break_interval)
        pomodoro_set -= 1
    
    print("Committed Pomodoros Complete!")

def continue_pomodoros(user_input, pomodoro_set, focus_interval, break_interval, total_focus_time):
    while True:
        while user_input == 'y':
            interval_settings = input('Do you want to use the same interval settings as last time (Enter y/n)? ')
            if interval_settings == 'y':
                pomodoro(pomodoro_set, focus_interval, break_interval)
                total_focus_time += (pomodoro_set*focus_interval)
                record_data(pomodoro_set, focus_interval, break_interval, total_focus_time)
                user_input = input('Do you want to continue with more pomodoros (Enter y/n)? ')
            else:
                return True
        if user_input == 'n':
            print('Goodbye.')
            return False
        else: 
            user_input = input('Do you want to continue with more pomodoros (Please enter a valid value y/n)? ')

def record_data(pomodoro_set, focus_interval, break_interval, total_focus_time):
    with open('Recorded Pomodoros', 'a') as record_of_pomodoros:
        session_info = f'This session consisted of {pomodoro_set} pomodoro(s) with {focus_interval} min focus intervals and {break_interval} min break intervals.'
        record_of_pomodoros.write(session_info + '\n')
        record_of_pomodoros.write(f'Your total focus time for this session was {total_focus_time} mins.\n')
        # for line in (record_of_pomodoros.readlines() [-2:]):
        #     print(line, end='')
        record_of_pomodoros.close

def record_session_finished():
    with open('Recorded Pomodoros', 'a') as record_of_pomodoros:
        record_of_pomodoros.write('END OF SESSION.\n\n')
        # for line in (record_of_pomodoros.readlines() [-1:]):
        #     print(line, end='')
        record_of_pomodoros.close

def main():

    total_focus_time = 0

    while True:

        # ask the user how long they want their focus intervals to be
        focus_interval = int(input('Enter the length of your focus interval (25 mins recommended): '))

        # ask the user how long they want their break interval to be
        break_interval = int(input('Enter the length of your break interval (5 mins recommended): '))

        # ask the user how many Pomodoros they want to run
        pomodoro_set = int(input('Enter the number of Pomodoros you want to commit to: '))
        
        # use the user inputs to start a set of pomodor timers
        pomodoro(pomodoro_set, focus_interval, break_interval)
        total_focus_time += (pomodoro_set*focus_interval)

        record_data(pomodoro_set, focus_interval, break_interval, total_focus_time)

        # ask the user if they want to continue or exit the program and take an action based on that
        repeat = input('Do you want to continue with more pomodoros (Enter y/n)? ')
        if continue_pomodoros(repeat, pomodoro_set, focus_interval, break_interval, total_focus_time) == False:
            break
    
    record_session_finished()

if __name__ == '__main__': main()








