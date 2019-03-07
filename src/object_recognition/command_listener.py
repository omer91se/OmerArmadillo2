from voice_recognition import SpeechDetector
from tts import tts, ding

from time import sleep


class SyncListener:
    def __init__(self):
        self.answer = None

    def listen(self):
        listen_to_command(self.final_callback)
        while self.answer is None:
            sleep(0.05)

        return self.answer

    def final_callback(self, answer):
        self.answer = answer


def listen_to_command(final_callback):
    #tts('Hi there! What do you want?')
    sd = SpeechDetector()
    sd.run(answer_callback, final_callback)


def answer_callback(answer, final_callback):
    print(answer)
    if answer=='<unrecognized speech>':
        tts('I didn\'t understand. Please try again.')
        sd = SpeechDetector()
        sd.run(answer_callback, final_callback)
        return

    final_callback(answer)


def main():
    listener = SyncListener()
    print(listener.listen())


if __name__ == '__main__':
    main()
