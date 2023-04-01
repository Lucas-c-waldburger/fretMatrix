#include <iostream>
#include "util.h"
#include "Note.h"


Note* assignNoteData(std::pair<int, double> (&noteData)[12][9], int name, float frequency, int fretRow, int fretColumn) {
    for (int row = 0; row < 12; row++) {
        for (int col = 0; col < 9; col++) {
            if (noteData[row][col].first == name && noteData[row][col].second == frequency) {
                return new Note(noteData[row][col].first, noteData[row][col].second, fretRow, fretColumn);
            }
        }
    }
}

Note* constructNote(std::pair<int, double> (&noteData)[12][9], int (&semitoneStringOffsets)[5], int name,
                    float frequency, int fretRow, int fretColumn, int fretRowMax, int fretColMax, Note* currNote) {

    if (fretRow >= fretRowMax || fretColumn >= fretColMax) {
        return nullptr;
    }

    Note* tempNew = assignNoteData(noteData, name, frequency, fretRow, fretColumn);

//    currNote->rightNext = tempNew;

    tempNew->upNext = currNote;

    tempNew->leftNext = currNote;

    tempNew->rightNext = constructNote(noteData, semitoneStringOffsets, name + semitoneStringOffsets[fretRow] + 1,
                                       frequency, fretRow, fretColumn + 1, fretRowMax, fretColMax, tempNew);

    tempNew->downNext = constructNote(noteData, semitoneStringOffsets, name + 1,
                                       frequency, fretRow + 1, fretColumn, fretRowMax, fretColMax, tempNew);

    return tempNew;
}




//
//    for (int r = 0; r < rows; r++) {
//        for (int c = 0; c < columns; c++) {
//            std::pair<int, double> noteDataPair;
//
//            if (r == 0 && c == 0) {
//                noteDataPair.first = startingName;
//                noteDataPair.second = frequencies[startingName][startingFrequency];
//            }
//
//            else {
//                int currName = (startingName + (semitoneStringOffsets[c - 1] + 1)) % 12;
//                noteDataPair.first = currName;
//
//                int currFreq;
//                if ((startingName + (semitoneStringOffsets[c - 1] + 1)) > 9) {
//                    currFreq = startingFrequency + r;
//                }
//                else {
//                    currFreq = startingFrequency + r + (c - 1);
//                }
//                noteDataPair.second = frequencies[currName][currFreq];
//            }
//
//            startingName = noteDataPair.first;
//
//
//            noteData[r][c] = noteDataPair;
//
//            std::cout << semitoneStringOffsets[c] << '\n';
//            std::cout << "(" << r << ", " << c << ") - " << noteData[r][c].first << ", " << noteData[r][c].second << '\n';
//        }
//    }
//}


void fillNoteData(std::pair<int, double> (&noteData)[12][9]) {
    for (int row = 0; row < 12; row++) {
        double startingFreq = startingFrequencies[row];
        for (int col = 0; col < 9; col++) {
            std::pair<int, double> noteDataPair = {row, startingFreq};
            noteData[row][col] = noteDataPair;
            startingFreq *= 2;
        }
    }
}


void printList(Note* note) {
    while (note != nullptr) {
        std::cout << note << " - (" << note->fretRow << ", " << note->fretColumn << ") - " << note->frequency << '\n';

        note = note->leftNext;

    }
}

int main() {



//    std::pair<int, double> noteData[12][9];
//    fillNoteData(noteData);
//
//    for (int row = 0; row < 12; row++) {
//        for (int col = 0; col < 9; col++) {
//            std::cout << "(" << row << ", " << col << ") - " << noteData[row][col].first << ", " << noteData[row][col].second << '\n';
//
//        }
//    }

    int fretboardRowMax = 4;
    int fretboardColMax = 6;

    Note* openStrings[6] = {
        new Note(E, oct2, 0, 0),
        new Note(A, oct2, 0, 1),
        new Note(D, oct3, 0, 2),
        new Note(G, oct3, 0, 3),
        new Note(B, oct3, 0, 4),
        new Note(E, oct4, 0, 5),
    };

    for (int col = 0; col < fretboardColMax; col++) {
        Note *currNote = openStrings[col];
        for (int row = 0; row < fretboardRowMax; row++) {

            int nextOctave = currNote->octave;
            if (currNote->name + 1 == 0) {nextOctave = currNote->octave + 1;}

            Note *tempNote = new Note((currNote->name + 1) % 12, nextOctave, currNote->fretRow + 1, currNote->fretColumn);

            currNote->downNext = tempNote;
            tempNote->upNext = currNote;
            currNote = tempNote;
        }
    }
    Note* startingNote = openStrings[0];
    Note* currNote;
    for (int row = 0; row < fretboardRowMax; row++) {
        currNote = startingNote;
        for (int col = 0; col < fretboardColMax - 1; col++) {
                currNote->rightNext = openStrings[col + 1];
                openStrings[col + 1]->leftNext = currNote;
                currNote = openStrings[col + 1];
            }
        startingNote = startingNote->downNext;
    }



    printList(openStrings[5]);

    return 0;
}
