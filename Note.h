
#ifndef FRETMATRIX_NOTE_H
#define FRETMATRIX_NOTE_H
#include <utility>


enum NoteNames {
    C = 0,
    Db = 1,
    D = 2,
    Eb = 3,
    E = 4,
    F = 5,
    Gb = 6,
    G = 7,
    Ab = 8,
    A = 9,
    Bb = 10,
    B = 11
};

enum Octaves {
    oct0 = 0,
    oct1 = 1,
    oct2 = 2,
    oct3 = 3,
    oct4 = 4,
    oct5 = 5,
    oct6 = 6,
    oct7 = 7,
    oct8 = 8,
};



double frequencies[12][9] = {
    {16.35, 32.70, 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01},
    {17.32, 34.65, 69.30, 138.59, 277.18, 554.37, 1108.73, 2217.46, 4434.92},
    {18.35, 36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.63},
    {19.45, 38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489.02, 4978.03},
    {20.60, 41.20, 82.41, 164.81, 329.63, 659.26, 1318.51, 2637.02, 5274.04},
    {21.83, 43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83, 5587.65},
    {23.12, 46.25, 92.50, 185.00, 369.99, 739.99, 1479.98, 2959.96, 5919.91},
    {24.50, 49.00, 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96, 6271.93},
    {25.96, 51.91, 103.83, 207.65, 415.30, 830.61, 1661.22, 3322.44, 6644.88},
    {27.50, 55.00, 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00, 7040.00},
    {29.14, 58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31, 7458.62},
    {30.87, 61.74, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.07, 7902.13}
};


double startingFrequencies[12] = {
        16.35,
        17.32,
        18.35,
        19.45,
        20.60,
        21.83,
        23.12,
        24.50,
        25.96,
        27.50,
        29.14,
        30.87
};

struct Note {
    Note(int name, int octave, int fretRow, int fretColumn) : name{name}, octave{octave}, fretRow{fretRow}, fretColumn{fretColumn} {
        frequency = frequencies[name][octave];
    };

    int name;
    int octave;
    double frequency;

    int fretRow;
    int fretColumn;

    Note *upNext = nullptr;
    Note *downNext = nullptr;
    Note *leftNext = nullptr;
    Note *rightNext = nullptr;

    friend std::ostream& operator<<(std::ostream& stream, const Note* note) {
        stream << nameIntToAlpha(note->name);
        return stream;
    }
};

//struct Note {
//    Note(int name, double frequency) : name{name}, frequency{frequency} {};
//    Note(int name, double frequency, int row, int column) : name{name}, frequency{frequency}, row{row},
//                                                            column{column} {};
//
//    int name;
//    double frequency;
//
//    int row;
//    int column;
//
//    Note *upNext = nullptr;
//    Note *downNext = nullptr;
//    Note *leftNext = nullptr;
//    Note *rightNext = nullptr;
//
//};

int getOctave(double frequency) {
    while (frequency > startingFrequencies[11]) {
        frequency /= 2;
    }
    for (int i = 0; i < 12; i++) {
        if (frequency == startingFrequencies[i]) {
            return i;
        }
    }
    return -1;
}


#endif //FRETMATRIX_NOTE_H
