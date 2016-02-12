using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace SoundLib
{
    public static class SoundLib
    {
        private static float tempo = 600.0f;
        public static void Beep(string note = "", float inverseFractionOfQuarterNote = 1.0f)
        {
            int n = 50;
            int l = (int)(tempo / inverseFractionOfQuarterNote);
            switch (note)
            {
                case "bell":
                case "Bell":
                case "BELL":
                case "\a": Console.Write('\a'); break;
                case "rest":
                case "r":
                case "R":
                case "REST":
                case "Rest":
                case "":
                case " ": Thread.Sleep(l); break;
                case "C1": n = 65; goto default; // n=2^((x+12)/12)*440 where x = number of semitones from A4
                case "C#1": n = 69; goto default;
                case "D1": n = 73; goto default;
                case "D#1": n = 78; goto default;
                case "E1": n = 82; goto default;
                case "F1": n = 87; goto default;
                case "F#1": n = 92; goto default;
                case "G1": n = 98; goto default;
                case "G#1": n = 104; goto default;
                case "A1": n = 110; goto default;
                case "A#1": n = 117; goto default;
                case "B1": n = 123; goto default;
                case "C2": n = 131; goto default;
                case "C#2": n = 139; goto default;
                case "D2": n = 147; goto default;
                case "D#2": n = 156; goto default;
                case "E2": n = 165; goto default;
                case "F2": n = 175; goto default;
                case "F#2": n = 185; goto default;
                case "G2": n = 196; goto default;
                case "G#2": n = 208; goto default;
                case "A2": n = 220; goto default;
                case "A#2": n = 233; goto default;
                case "B2": n = 247; goto default;
                case "C":
                case "C3": n = 262; goto default;
                case "C#":
                case "C#3": n = 277; goto default;
                case "D":
                case "D3": n = 294; goto default;
                case "D#":
                case "D#3": n = 311; goto default;
                case "E":
                case "E3": n = 330; goto default;
                case "F":
                case "F3": n = 349; goto default;
                case "F#":
                case "F#3": n = 370; goto default;
                case "G":
                case "G3": n = 392; goto default;
                case "G#":
                case "G#3": n = 415; goto default;
                case "A":
                case "A3": n = 440; goto default;
                case "A#":
                case "A#3": n = 466; goto default;
                case "B":
                case "B3": n = 494; goto default;
                case "C4": n = 523; goto default;
                case "C#4": n = 554; goto default;
                case "D4": n = 587; goto default;
                case "D#4": n = 622; goto default;
                case "E4": n = 659; goto default;
                case "F4": n = 698; goto default;
                case "F#4": n = 740; goto default;
                case "G4": n = 784; goto default;
                case "G#4": n = 831; goto default;
                case "A4": n = 880; goto default;
                case "A#4": n = 932; goto default;
                case "B4": n = 988; goto default;
                case "C5": n = 1047; goto default;
                case "C#5": n = 1109; goto default;
                case "D5": n = 1175; goto default;
                case "D#5": n = 1245; goto default;
                case "E5": n = 1319; goto default;
                case "F5": n = 1397; goto default;
                case "F#5": n = 1480; goto default;
                case "G5": n = 1568; goto default;
                case "G#5": n = 1661; goto default;
                case "A5": n = 1760; goto default;
                case "A#5": n = 1865; goto default;
                case "B5": n = 1976; goto default;
                case "C6": n = 2093; goto default;
                default:
                    Console.Beep(n, l); break;
            }
        }

        public enum TrackName { SMBDie, SMBWin, NSMBBGM, SMDDie, SMDWin, SMDBGM, ReconstructingMoreScience, YourPreciousMoon, MagicRoundabout, AllStar, Umaru, Stop }

        public static void musicSMBDie() { float initTempo = tempo; tempo = 600.0f; Beep("B3", 4); Beep("F4", 2); Beep("F4", 4); Beep("F4", 3); Beep("E4", 3); Beep("D4", 3); Beep("C4", 4); Beep("E3", 2); Beep("E3", 4); Beep("C3", 2); tempo = initTempo; }
        public static void musicSMBWin() { float initTempo = tempo; tempo = 600.0f; Beep("G2", 3); Beep("C3", 3); Beep("E3", 3); Beep("G3", 3); Beep("C4", 3); Beep("E4", 3); Beep("G4", 1); Beep("E4", 1); Beep("G#2", 3); Beep("C3", 3); Beep("D#3", 3); Beep("G#3", 3); Beep("C4", 3); Beep("D#4", 3); Beep("G#4", 1); Beep("D#4", 1); Beep("A#2", 3); Beep("D3", 3); Beep("F3", 3); Beep("A#3", 3); Beep("D4", 3); Beep("F4", 3); Beep("A#4", 1); Beep("A#4", 3); Beep("A#4", 3); Beep("A#4", 3); Beep("C5", 0.5f); tempo = initTempo; }
        public static void musicNSMBBGM()
        {
            while (true)
            {
                tempo = 300.0f;
                for (byte b0 = 0; b0 < 2; b0++)
                {
                    Beep(" "); Beep("E4", 2); Beep("G4"); Beep("C5", 2); Beep("A4"); Beep("G4", 2); Beep("D#4"); Beep("E4", 2);
                    Beep(" "); Beep("G4", 2); Beep("C#5"); Beep("G4", 2); Beep("A4"); Beep("C#5", 2); Beep("A4"); Beep("G4", 2);
                    Beep(" "); Beep("G4", 2); Beep("A4"); Beep("D5", 2); Beep("C5"); Beep("A4", 2); Beep("F4"); Beep("A4", 2);
                    Beep("F5"); Beep("B4", 2); Beep("D5"); Beep("F4", 2); Beep("B4"); Beep("A#4", 2); Beep("A4"); Beep("G4", 2);
                }

                for (byte b0 = 0; b0 < 2; b0++)
                {
                    Beep(" ", 2.0f / 3.0f); Beep("E"); Beep("F", 2); Beep("G"); Beep("A", 2); Beep(" "); Beep("E", 2);
                    Beep(" "); Beep("G", 2); Beep(" "); Beep("G#", 2); Beep("A", 2.0f / 9.0f);
                    Beep("E"); Beep("F", 2); Beep("G"); Beep("A", 2); Beep(" "); Beep("B", 2);
                    Beep(" "); Beep("B", 2); Beep(" "); Beep("A#", 2); Beep("A", 2.0f / 9.0f);

                    Beep("D"); Beep("E", 2); Beep("F"); Beep("G", 2); Beep(" "); Beep("D", 2);
                    Beep(" "); Beep("F", 2); Beep(" "); Beep("F#", 2); Beep("G", 2.0f / 9.0f);
                    Beep("D"); Beep("E", 2); Beep("F"); Beep("G", 2); Beep(" "); Beep("A", 2);
                    Beep(" "); Beep("A", 2); Beep(" "); Beep("G#", 2); Beep("G", 2.0f / 9.0f);

                    Beep("E"); Beep("F", 2); Beep("G"); Beep("A", 2); Beep(" "); Beep("E", 2);
                    Beep(" "); Beep("G", 2); Beep(" "); Beep("G#", 2); Beep("A", 2.0f / 9.0f);

                    Beep("E", 2); Beep("F", 2.0f / 3.0f); Beep("G", 8.0f / 9.0f); Beep("A", 8.0f / 9.0f); Beep("A#", 4.0f / 3.0f);
                    Beep("A", 0.25f); Beep(" ", 2.0f / 3.0f); Beep("G#", 2);
                    Beep("A"); Beep("B", 2); Beep("C4"); Beep("D4", 2); Beep(""); Beep("A", 2); Beep("B"); Beep("C4", 2);
                    Beep("D4", 1.0f / 3.0f); Beep("C4", 2.0f / 3.0f); Beep("D4", 2.0f / 3.0f);
                    Beep("E4", 2.0f / 3.0f); Beep("E4"); Beep("C4", 2); Beep(); Beep("G", 2); Beep(); Beep("B", 2);
                    Beep("B", 0.4f); Beep("A", 2.0f / 3.0f); Beep("", 2.0f / 3.0f); Beep("G#", 2);
                    Beep("A"); Beep("B", 2); Beep("C4"); Beep("D4", 2); Beep(""); Beep("A", 2); Beep("B"); Beep("C4", 2);
                    Beep("D4", 1.0f / 3.0f); Beep("E4", 1.0f / 3.0f);
                    Beep("C4", 1.0f / 6.0f);
                    Beep("bell"); Beep("G", 0.5f); Beep("", 2); Beep("bell"); Beep("G", 2.0f / 3.0f); Beep("", 0.5f);
                }

                Beep("G4"); Beep("A4", 2); Beep(); Beep("D#4", 2); Beep("E4", 2.0f / 3.0f); Beep("G"); Beep("A", 2);
                Beep(); Beep("D#", 2); Beep("E", 2.0f / 3.0f); Beep("A"); Beep("G", 2); Beep("E"); Beep("C", 2);
                Beep("A#2"); Beep("B2", 2); Beep("F#"); Beep("A#2", 2); Beep("B2"); Beep("F#", 2); Beep("A#2"); Beep("B2", 2);
                Beep("G", 0.25f); Beep("", 0.5f);

                Beep("F4"); Beep("G4", 2); Beep(); Beep("C#4", 2); Beep("D4", 2.0f / 3.0f); Beep("A#"); Beep("B", 2);
                Beep(); Beep("F", 2); Beep("G", 2.0f / 3.0f); Beep("B"); Beep("G", 2); Beep("F"); Beep("D", 2);
                Beep("D#"); Beep("E", 2); Beep("A"); Beep("D#", 2); Beep("E"); Beep("A", 2); Beep("D#"); Beep("E", 2);
                Beep("A", 0.25f); Beep("", 0.5f);

                Beep("G4"); Beep("A4", 2); Beep(); Beep("D#4", 2); Beep("E4", 2.0f / 3.0f); Beep("G"); Beep("A", 2);
                Beep(); Beep("D#", 2); Beep("E", 2.0f / 3.0f); Beep("A"); Beep("G", 2); Beep("E"); Beep("C", 2);
                Beep("C5"); Beep("D5", 2); Beep(); Beep("G#4", 2); Beep("A4", 2.0f / 3.0f); Beep("E4"); Beep("F4", 0.5f);
                Beep("", 2.0f / 9.0f);

                Beep("C5"); Beep("D5", 2); Beep(); Beep("G#4", 2); Beep("A4", 2.0f / 3.0f); Beep("C5"); Beep("D5", 0.5f);
                Beep(); Beep("G#4", 2); Beep("A4", 2.0f / 3.0f); Beep("C5"); Beep("D5", 2); Beep("G#4"); Beep("A4", 2);

                Beep("C5"); Beep("D5", 2); Beep(); Beep("G4", 2); Beep("A4", 2.0f / 3.0f); Beep("C5"); Beep("D5", 0.5f);
                Beep(); Beep("G4", 2); Beep("A4", 2.0f / 3.0f); Beep("C5"); Beep("D5", 2); Beep("G4"); Beep("A4", 2);

                Beep("D#4"); Beep("E4", 2); Beep("A4"); Beep("D#4", 2); Beep("E4"); Beep("A4", 2); Beep("D#4"); Beep("E4", 2); Beep("A4"); Beep("D#4", 2); Beep("E4"); Beep("G4", 2); Beep("D#4"); Beep("E4", 2); Beep("C4"); Beep("A", 2); Beep("C4", 0.25f);
                Beep("G1", 2.0f / 3.0f); Beep("G1", 2.0f / 3.0f); Beep("A1", 2.0f / 3.0f); Beep("B1", 2.0f / 3.0f);
            }
        }
        public static void musicSMBDieBass() { tempo = 600.0f; Beep("G2", 2); Beep(" ", 4); Beep("G2", 4); Beep("G2", 3); Beep("A2", 3); Beep("B2", 3); Beep("C3", 2); Beep("G2", 2); Beep("C2", 2); }

        public static void musicSMDWin() { float initTempo = tempo; tempo = 350.0f; Beep("G3", 2); Beep("G3", 2); Beep("C4"); Beep("B3"); Beep("G3", 2); Beep("G3", 2); Beep("C4"); Beep("B3"); Beep("G3", 2); Beep("G3", 2); Beep("C4"); Beep("B3", 0.5f); Beep("C5", 2); Beep("B4", 2); Beep("G4", 2); Beep("A4", 0.2f); tempo = initTempo; }

        public static void musicReconstructScience()
        {
            float initTempo = tempo; tempo = 600.0f;
            for (byte b0 = 0; b0 < 2; b0++) // this loop pitched up one octave due to poor fish handling
            {
            Beep("F3", 2); Beep("C4", 2); Beep("G3", 2); Beep("G#3", 2); Beep("F3", 2); Beep("C4", 2); Beep("G3", 2); Beep("A#3", 2);
            Beep("F3", 2); Beep("C4", 2); Beep("G3", 2); Beep("G#3", 2); Beep("A#3", 2); Beep("G#3", 2); Beep("G3", 2); Beep("G#3", 2);
            }
            for (byte b0 = 0; b0 < 2; b0++)
            {
            Beep("F"); Beep("C4"); Beep("G#"); Beep("A#"); Beep("G"); Beep("G#"); Beep("F"); Beep("E");
            Beep("F"); Beep("C4"); Beep("G#"); Beep("A#"); Beep("C#4"); Beep("G"); Beep("A#"); Beep("E");
            }
            for (byte b0 = 0; b0 < 2; b0++)
            {
                Beep("F4"); Beep("C5"); Beep("G#4"); Beep("A#4"); Beep("G4"); Beep("G#4"); Beep("F4"); Beep("E4");
                Beep("F4"); Beep("C5"); Beep("G#4"); Beep("A#4"); Beep("C#5"); Beep("G4"); Beep("A#4"); Beep("E4");
            }
            for (byte b0 = 0; b0 < 2; b0++)
            {
                Beep("F4", 2); Beep("C5", 2); Beep("G4", 2); Beep("G#4", 2); Beep("F4", 2); Beep("C5", 2); Beep("G4", 2); Beep("A#4", 2);
                Beep("F4", 2); Beep("C5", 2); Beep("G4", 2); Beep("G#4", 2); Beep("A#4", 2); Beep("G#4", 2); Beep("G4", 2); Beep("G#4", 2);
            }
            Beep("F4", 0.5f); Beep("F4", 0.5f); Beep("F4", 0.25f);
            tempo = initTempo;
        }
        public static void musicPreciousMoon()
        {
            float initTempo = tempo; tempo = 600.0f;
            Beep("F4", 2);
            for (byte b0 = 0; b0 < 14; b0++)
            {
                Beep("E4", 2); Beep("F4", 2); Beep("D4", 2); Beep("F4", 2);
            }
            Beep("D4", 2); Beep("A#4", 2); Beep("G4", 2); Beep("A4", 2); Beep("C#5", 2); Beep("A4", 2); Beep("A#4", 2); Beep("G4", 2);
            for (byte b0 = 0; b0 < 3; b0++)
            {
                Beep("D4", 2); Beep("A4", 2); Beep("G4", 2); Beep("A4", 2); Beep("F4", 2); Beep("G4", 2); Beep("E4", 2); Beep("F4", 2);
            }
            Beep("D4", 2); Beep("A#4", 2); Beep("G4", 2); Beep("A4", 2); Beep("C#5", 2); Beep("A4", 2); Beep("A#4", 2); Beep("G4", 0.125f);
            tempo = initTempo;
        }

        public static void musicMagicRnd()
        {
            float initTempo = tempo; tempo = 500.0f;
            for (byte b0 = 0; b0 < 2; b0++)
            {
                Beep("C5"); Beep("C5", 2); Beep("C5", 2); Beep("G4"); Beep("G4");
                Beep("A4"); Beep("A4", 2); Beep("A4", 2); Beep("F4", 0.5f);
                Beep("A#4"); Beep("A#4", 2); Beep("A#4", 2); Beep("F4"); Beep("F4");
                Beep("B4"); Beep("B4", 2); Beep("B4", 2); if (b0<1) Beep("G4", 0.5f);
            }
            Beep("G4"); Beep("G4"); Beep("C5", 0.2f);
            tempo = initTempo;
        }
        public static void musicUMR()
        {
            float initTempo = tempo; tempo = 600.0f;
            Beep("F#", 4); Beep("F#", 4); Beep("F#", 2); Beep("G", 2);
            Beep("A", 1.666f); Beep("A", 1.666f); Beep("B", 2); Beep("A", 2); Beep("G", 2); Beep("F#", 2); Beep("G", 2);
            Beep("A", 2); Beep("A", 4); Beep("A", 1.666f); Beep("B", 2); Beep("A"); Beep("R", 2); Beep("A", 2);
            Beep("D"); Beep("R", 2); Beep("A", 2); Beep("D"); Beep("R", 2); Beep("A", 2);
            Beep("B2", 2); Beep("C#", 2); Beep("D", 2); Beep("F#", 2); Beep("F#", 1.666f); Beep("E", 4); Beep("E");
            Beep("A", 1.666f); Beep("A", 1.666f); Beep("B", 2); Beep("A", 2); Beep("G", 2); Beep("F#", 2); Beep("G", 2);
            Beep("A", 1.666f); Beep("D4", 1.666f); Beep("C#4", 2); Beep("D4"); Beep("R", 2); Beep("D", 2);
            Beep("B2", 2); Beep("C#", 2); Beep("D", 2); Beep("F#", 2); Beep("E", 0.666f); Beep("D", 2);
            Beep("D", 0.5f); Beep("D5"); Beep("D5"); Beep("D5"); Beep("D5"); Beep("D5", 4); Beep("F#5", 2); Beep("F#5", 4); Beep("E5", 2); Beep("D5", 2); Beep("D5"); Beep("D5"); Beep("D5"); Beep("D5"); Beep("G4", 1.666f); Beep("F#4", 1.666f); Beep("G4", 2); Beep("A4"); Beep();

            Beep("D", 1.666f); Beep("D", 1.666f); Beep("C#", 2); Beep("D"); Beep("R", 2); Beep("D", 4); Beep("E", 4);
            Beep("F#", 1.666f); Beep("E", 1.666f); Beep("D", 2); Beep("BELL"); Beep("E"); Beep("BELL"); Beep("R", 2); Beep("D", 4); Beep("E", 4);
            Beep("G", 1.666f); Beep("G", 1.666f); Beep("F#", 2); Beep("G", 2); Beep("F#", 2); Beep("E", 2); Beep("F#", 2);
            Beep("E", 1.666f); Beep("E", 1.666f); Beep("F#", 2); Beep("F#"); Beep("R", 2); Beep("B2", 4); Beep("C#", 4);
            Beep("D", 1.666f); Beep("BELL"); Beep("D", 1.666f); Beep("BELL"); Beep("C#", 2); Beep("BELL"); Beep("D"); Beep("BELL"); Beep("R", 2); Beep("D", 4); Beep("E", 4);
            Beep("F#", 1.666f); Beep("E", 1.666f); Beep("D", 2); Beep("E"); Beep("R", 2); Beep("D", 4); Beep("E", 4);
            Beep("G", 1.666f); Beep("G", 1.666f); Beep("F#", 2); Beep("G", 2); Beep("F#", 2); Beep("E", 2); Beep("F#", 2);
            Beep("D"); Beep("A"); Beep("D"); Beep("B", 8); Beep("A", 8); Beep("B", 8); Beep("A", 8); Beep("B", 8); Beep("A", 8); Beep("G", 4);
            //Bar 26
            Beep("F#", 1.666f); Beep("F#", 4); Beep("F#", 4); Beep("F#", 4); Beep("G", 2); Beep("F#", 2); Beep("E", 2);
            Beep("F#", 4); Beep("G", 4); Beep("F#", 4); Beep("G", 4); Beep("F#", 4); Beep("D", 4); Beep("B2"); Beep("B2", 2);
            Beep("F#", 1.666f); Beep("F#", 4); Beep("F#", 4); Beep("F#", 4); Beep("G", 2); Beep("F#", 2); Beep("E", 2);
            Beep("E", 1.666f); Beep("E", 4); Beep("E", 2); Beep("E", 2); Beep("D", 2); Beep("E", 2);
            Beep("F#", 1.666f); Beep("G", 4); Beep("F#", 4); Beep("G", 4); Beep("F#"); Beep("D", 4); Beep("E", 4);
            Beep("F#", 1.666f); Beep("F#", 4); Beep("F#", 2); Beep("G", 2); Beep("F#", 2); Beep("E", 2);
            //Bar 31
            Beep("F#", 4); Beep("G", 4); Beep("F#", 4); Beep("G", 4); Beep("F#", 4); Beep("C#4", 4);
            Beep("B"); Beep("B", 2); Beep("A", 2);
            Beep("G", 1.666f); Beep("G", 1.666f); Beep("G", 2); Beep("A", 2); Beep("G", 2); Beep("F#", 2); Beep("G", 2);
            Beep("A", 1.666f); Beep("F#", 1.666f); Beep("A", 2); Beep("B"); Beep("B", 2); Beep("A", 2);
            Beep("G", 0.666f); Beep("G"); Beep("G", 2); Beep("F#", 2); Beep("G", 2);
            Beep("A", 0.5f);
            
            Beep("R", 2);
            
            Beep("F#", 4); Beep("F#", 4); Beep("F#", 2); Beep("G", 2);
            Beep("A", 1.666f); Beep("A", 2); Beep("A", 4); Beep("B", 2); Beep("A", 2); Beep("G", 2); Beep("F#", 2); Beep("G", 2);
            Beep("A", 1.666f); Beep("A", 1.666f); Beep("B", 2); Beep("A"); Beep("R", 2); Beep("A", 2);
            Beep("D"); Beep("R", 2); Beep("A", 2); Beep("D"); Beep("R", 2); Beep("D", 2);
            Beep("B2", 2); Beep("C#", 2); Beep("D", 2); Beep("F#", 2); Beep("F#", 1.666f); Beep("E", 4); Beep("E");
            Beep("A", 1.666f); Beep("A", 1.666f); Beep("B", 2); Beep("A", 2); Beep("G", 2); Beep("F#", 2); Beep("G", 2);
            Beep("A", 1.666f); Beep("D4", 1.666f); Beep("C#4", 2); Beep("D4"); Beep("R", 2); Beep("A", 2);
            Beep("D"); Beep("R", 2); Beep("A", 2); Beep("D"); Beep("R", 2); Beep("D", 2);
            Beep("B2", 2); Beep("C#", 2); Beep("D", 2); Beep("F#", 2); Beep("F#"); Beep("E", 2); Beep("D", 2);
            Beep("D"); Beep("R", 2); Beep("D", 2); Beep("C#", 2); Beep("E", 2); Beep("B", 2);
            Beep("A", 1.666f); Beep("F#", 1.666f); Beep("A", 2); Beep("D4"); Beep("R", 2); Beep("D", 2);
            Beep("F#", 2); Beep("G", 2); Beep("F#", 2); Beep("G", 2); Beep("A", 2); Beep("D", 2); Beep("E", 2); Beep("E", 2);
            Beep("D", 0.5f); Beep("R", 2); Beep("C#5", 2); Beep("D5", 2); Beep("E5", 2);
            Beep("F#5", 4); Beep("G5", 4); Beep("F#5"); Beep("D5", 0.666f); Beep();
            //Bar 50
            Beep("F#4"); Beep("G4"); Beep("G#4"); Beep("A4"); Beep("A#4"); Beep("B4"); Beep("C5"); Beep("C#5"); Beep("D5", 0.5f); Beep("R", 0.5f);
            Beep("D", 1.666f); Beep("C", 1.666f); Beep("C#", 2); Beep("D");
            tempo = initTempo;
        }

        public static void musicAllStar()
        {
            float initTempo = tempo; tempo = 550.0f;
            Console.Write("Some");
            Beep("F#");
            Console.Write("bo");
            Beep("C#4", 2);
            Console.Write("dy ");
            Beep("A#", 2);
            Console.Write("once ");
            Beep("A#");
            Console.Write("told ");
            Beep("G#", 2);
            Console.Write("me ");
            Beep("F#", 2);
            Console.Write("the ");
            Beep("F#", 2);
            Console.Write("world ");
            Beep("B");
            Console.Write("is ");
            Beep("A#", 2);
            Console.Write("gon");
            Beep("A#", 2);
            Console.Write("na ");
            Beep("G#", 2);
            Console.Write("roll ");
            Beep("G#", 2);
            Console.WriteLine("me,");
            Beep("F#", 2);
            Beep("", 2);

            Console.Write("I ");
            Beep("F#", 2);
            Console.Write("ain't ");
            Beep("C#4", 2);
            Console.Write("the ");
            Beep("A#", 2);
            Console.Write("sharp");
            Beep("A#", 2);
            Console.Write("est ");
            Beep("G#", 2);
            Console.Write("tool ");
            Beep("G#", 2);
            Console.Write("in ");
            Beep("F#", 2);
            Console.Write("the ");
            Beep("F#", 2);
            Console.Write("sh");
            Beep("D#");
            Console.WriteLine("ed");
            Beep("C#", 0.666f);
            Beep();

            Console.Write("She ");
            Beep("F#", 2);
            Console.Write("was ");
            Beep("F#", 2);
            Console.Write("look");
            Beep("C#4", 2);
            Console.Write("ing ");
            Beep("A#", 2);
            Console.Write("kind ");
            Beep("A#", 2);
            Console.Write("of ");
            Beep("G#", 2);
            Console.WriteLine("dumb ");
            Beep("G#", 2);
            Console.Write("with ");
            Beep("F#", 2);
            Console.Write("her ");
            Beep("F#", 2);
            Console.Write("fin");
            Beep("B");
            Console.Write("ger ");
            Beep("A#", 2);
            Console.Write("and ");
            Beep("A#", 2);
            Console.Write("her ");
            Beep("G#", 2);
            Console.Write("thumb ");
            Beep("G#", 2);
            Console.Write("in ");
            Beep("F#", 2);
            Console.Write("the ");
            Beep("F#", 2);
            Console.Write("shape ");
            Beep("C#4");
            Console.Write("of ");
            Beep("A#", 2);
            Console.Write("an ");
            Beep("A#", 2);
            Console.Write("L ");
            Beep("G#");
            Console.Write("on ");
            Beep("F#", 2);
            Console.Write("her ");
            Beep("F#", 2);
            Console.Write("fore");
            Beep("G#");
            Console.WriteLine("head");
            Beep("D#", 0.666f);
            Beep();

            Console.Write("Well, ");
            Beep("F#", 1.333f);
            Console.Write("the ");
            Beep("F#", 4);
            Console.Write("years ");
            Beep("F#", 2);
            Console.Write("start ");
            Beep("F#", 2);
            Console.Write("com");
            Beep("F#", 4);
            Console.Write("ing ");
            Beep("F#", 4);
            Console.Write("and ");
            Beep("F#", 4);
            Console.Write("they ");
            Beep("F#", 4);
            Console.Write("don't ");
            Beep("F#", 2);
            Console.Write("stop ");
            Beep("F#", 2);
            Console.Write("com");
            Beep("F#", 4);
            Console.WriteLine("ing,");
            Beep("F#", 1.333f);

            Console.Write("Fed ");
            Beep("F#", 2);
            Console.Write("to ");
            Beep("F#", 4);
            Console.Write("the ");
            Beep("F#", 4);
            Console.Write("rules ");
            Beep("F#", 2);
            Console.Write("and ");
            Beep("F#", 4);
            Console.Write("I ");
            Beep("F#", 4);
            Console.Write("hit ");
            Beep("F#", 4);
            Console.Write("the ");
            Beep("F#", 4);
            Console.Write("ground ");
            Beep("F#", 2);
            Console.Write("run");
            Beep("A#", 4);
            Console.WriteLine("ning,");
            Beep("F#", 1.333f);

            Console.Write("Did");
            Beep("A#", 4);
            Console.Write("n't ");
            Beep("C#4", 4);
            Console.Write("make ");
            Beep("C#4", 2);
            Console.Write("sense ");
            Beep("C#4", 2);
            Console.Write("not ");
            Beep("B", 4);
            Console.Write("to ");
            Beep("B", 4);
            Console.Write("live ");
            Beep("A#", 2);
            Console.Write("for ");
            Beep("A#", 2);
            Console.WriteLine("fun");
            Beep("A#", 1.333f);

            Console.Write("Your ");
            Beep("C#", 4);
            Console.Write("brain ");
            Beep("A#", 2);
            Console.Write("gets ");
            Beep("F#", 2);
            Console.Write("smart ");
            Beep("F#", 2);
            Console.Write("but ");
            Beep("F#", 4);
            Console.Write("your ");
            Beep("D#", 4);
            Console.Write("head ");
            Beep("F#", 2);
            Console.Write("gets ");
            Beep("F#", 2);
            Console.Write("du");
            Beep("D#", 4);
            Console.WriteLine("mb");
            Beep("C#", 1.333f);

            //Bar 14
            Console.Write("So ");
            Beep("A#", 4);
            Console.Write("much ");
            Beep("C#4", 2);
            Console.Write("to ");
            Beep("A#", 4);
            Console.Write("do, ");
            Beep("D#4", 2);
            Console.Write("so ");
            Beep("A#", 4);
            Console.Write("much ");
            Beep("C#4", 2);
            Console.Write("to ");
            Beep("A#", 4);
            Console.WriteLine("see, ");
            Beep("D#4", 2);
            Console.Write("so ");
            Beep("A#", 4);
            Console.Write("what's ");
            Beep("C#4", 2);
            Console.Write("wrong ");
            Beep("B", 2);
            Console.Write("with ");
            Beep("A#", 2);
            Console.Write("tak");
            Beep("G#", 2);
            Console.Write("ing ");
            Beep("G#", 2);
            Console.Write("the ");
            Beep("F#", 4);
            Console.Write("back ");
            Beep("G#", 2);
            Console.WriteLine("streets?");
            Beep("F#", 2);
            Beep("", 1.333f);

            Console.Write("You'll ");
            Beep("C#", 4);
            Console.Write("ne");
            Beep("F#", 4);
            Console.Write("ver ");
            Beep("F#", 4);
            Console.Write("know ");
            Beep("F#", 2);
            Console.Write("if ");
            Beep("F#", 4);
            Console.Write("you ");
            Beep("F#", 4);
            Console.Write("don't ");
            Beep("F#", 2);
            Console.WriteLine("go");
            Beep("F#");
            Beep("", 1.333f);

            Console.Write("You'll ");
            Beep("C#", 4);
            Console.Write("ne");
            Beep("A#", 4);
            Console.Write("ver ");
            Beep("F#", 4);
            Console.Write("shine ");
            Beep("F#", 2);
            Console.Write("if ");
            Beep("F#", 4);
            Console.Write("you ");
            Beep("D#", 4);
            Console.Write("don't ");
            Beep("D#", 2);
            Console.WriteLine("glow");
            Beep("D#");
            Beep();

            //Bar 18
            Console.Write("Hey ");
            Beep("A#", 2);
            Console.WriteLine("now");
            Beep("F#");
            Console.Write("You're ");
            Beep("F#", 4);
            Console.Write("an ");
            Beep("D#", 4);
            Console.Write("All ");
            Beep("F#", 2);
            Console.WriteLine("Star");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 4);
            Console.Write("your ");
            Beep("D#", 4);
            Console.Write("game ");
            Beep("F#", 2);
            Console.WriteLine("on");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Go ");
            Beep("F#", 2);
            Beep("", 2);
            Console.WriteLine("play");
            Beep("A#", 0.8f);

            //Bar 20
            Console.Write("Hey ");
            Beep("A#", 2);
            Console.WriteLine("now");
            Beep("F#");
            Console.Write("You're ");
            Beep("F#", 4);
            Console.Write("a ");
            Beep("D#", 4);
            Console.Write("rock ");
            Beep("F#", 2);
            Console.WriteLine("star");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 4);
            Console.Write("the ");
            Beep("D#", 4);
            Console.Write("show ");
            Beep("F#", 2);
            Console.WriteLine("on");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 2);
            Beep("", 2);
            Console.WriteLine("paid");
            Beep("A#", 0.8f);

            //Bar 22
            Console.Write("All ");
            Beep("A#");
            Console.Write("that ");
            Beep("C#4");
            Console.Write("glit");
            Beep("B", 2);
            Console.Write("ters ");
            Beep("A#", 2);
            Console.Write("is ");
            Beep("G#", 2);
            Console.Write("go");
            Beep("G#", 2);
            Console.WriteLine("ld");
            Beep("F#", 0.5f);

            Console.Write("Onl");
            Beep("F#", 2);
            Console.Write("y ");
            Beep("F#", 2);
            Console.Write("shoot");
            Beep("G#", 2);
            Console.Write("ing ");
            Beep("F#", 2);
            Console.Write("sta");
            Beep("A#", 2);
            Console.Write("rs ");
            Beep("G#", 0.8f);
            Console.Write("break ");
            Beep("G#", 2);
            Console.Write("the ");
            Beep("F#");
            Console.Write("mo");
            Beep("G#", 2);
            Console.Write("l");
            Beep("A#", 2);
            Console.WriteLine("d");
            Beep("D#", 0.333f);
            //
            //End chorus
            //

            Console.Write("It's ");
            Beep("F#", 4);
            Console.Write("a ");
            Beep("F#", 4);
            Console.Write("cool ");
            Beep("F#", 2);
            Console.Write("place, ");
            Beep("F#", 2); Beep("", 2);
            Console.Write("and ");
            Beep("F#", 4);
            Console.Write("they ");
            Beep("F#", 4);
            Console.Write("say ");
            Beep("F#", 4);
            Console.Write("it ");
            Beep("F#", 4);
            Console.Write("gets ");
            Beep("F#", 2);
            Console.Write("cold");
            Beep("F#", 4);
            Console.WriteLine("er");
            Beep("F#", 2);

            Console.Write("You're ");
            Beep("C#", 4);
            Console.Write("bund");
            Beep("F#", 4);
            Console.Write("led ");
            Beep("F#", 4);
            Console.Write("up ");
            Beep("F#", 2);
            Console.Write("now, ");
            Beep("F#", 2);
            Console.Write("wait ");
            Beep("F#", 2);
            Console.Write("'til ");
            Beep("F#", 4);
            Console.Write("you ");
            Beep("F#", 4);
            Console.Write("get ");
            Beep("F#", 2);
            Console.Write("old");
            Beep("A#", 4);
            Console.WriteLine("er");
            Beep("F#", 4);

            Console.Write("But ");
            Beep("C#", 4);
            Console.Write("the ");
            Beep("C#", 4);
            Console.Write("me");
            Beep("A#", 4);
            Console.Write("te");
            Beep("C#4", 4);
            Console.Write("or ");
            Beep("C#4", 4);
            Console.Write("men ");
            Beep("B", 2);
            Console.Write("beg ");
            Beep("A#", 2);
            Console.Write("to ");
            Beep("G#", 4);
            Console.Write("diff");
            Beep("G#", 4);
            Console.WriteLine("er");
            Beep("F#", 1.333f);
            Console.Write("Judg");
            Beep("F#", 4);
            Console.Write("ing ");
            Beep("F#", 4);
            Console.Write("by ");
            Beep("F#", 4);
            Console.Write("the ");
            Beep("G#", 4);
            Console.Write("hole ");
            Beep("A#", 2);
            Console.Write("in ");
            Beep("G#", 4);
            Console.Write("the ");
            Beep("F#", 4);
            Console.Write("sat");
            Beep("G#", 4);
            Console.Write("el");
            Beep("F#", 4);
            Console.Write("ite ");
            Beep("D#", 2);
            Console.Write("pic");
            Beep("D#", 4);
            Console.WriteLine("ture");
            Beep("D#", 2);

            Console.Write("The ");
            Beep("C#", 4);
            Console.Write("ice ");
            Beep("A#", 2);
            Console.Write("we ");
            Beep("C#4", 2);
            Console.Write("skate ");
            Beep("D#4", 1.333f);
            Console.Write("is ");
            Beep("C#", 4);
            Console.Write("get");
            Beep("A#", 4);
            Console.Write("ting ");
            Beep("F#", 4);
            Console.Write("pret");
            Beep("F#", 4);
            Console.Write("ty ");
            Beep("F#", 4);
            Console.WriteLine("thin");
            Beep("F#", 1.333f);

            Console.Write("The ");
            Beep("C#", 4);
            Console.Write("wa");
            Beep("F#", 4);
            Console.Write("ter's ");
            Beep("G#", 4);
            Console.Write("get");
            Beep("A#", 4);
            Console.Write("ting ");
            Beep("C#4", 4);
            Console.Write("warm ");
            Beep("B", 2);
            Console.Write("so ");
            Beep("A#", 4);
            Console.Write("you ");
            Beep("G#", 4);
            Console.Write("might ");
            Beep("A#", 4);
            Console.Write("as ");
            Beep("G#", 4);
            Console.Write("well ");
            Beep("D#", 2);
            Console.WriteLine("swim");
            Beep("D#", 1.333f);

            Console.Write("My ");
            Beep("C#", 4);
            Console.Write("world's ");
            Beep("D#4", 2);
            Console.Write("on ");
            Beep("C#4", 2);
            Console.Write("fi");
            Beep("C#4", 4);
            Console.Write("re, ");
            Beep("C#4", 1.333f);
            Console.Write("how ");
            Beep("A#", 4);
            Console.Write("'bout ");
            Beep("F#", 2);
            Console.WriteLine("yours? ");
            Beep("F#", 0.8f);

            Console.Write("But ");
            Beep("F#", 4);
            Console.Write("that's ");
            Beep("F#", 4);
            Console.Write("the ");
            Beep("F#", 4);
            Console.Write("way ");
            Beep("G#", 4);
            Console.Write("I ");
            Beep("A#", 4);
            Console.Write("like ");
            Beep("F#", 4);
            Console.Write("it ");
            Beep("F#", 4);
            Console.Write("and ");
            Beep("G#", 4);
            Console.Write("I'll ");
            Beep("A#", 4);
            Console.Write("never ");
            Beep("F#", 4);
            Console.Write("get ");
            Beep("D#", 2);
            Console.WriteLine("bored");
            Beep("D#", 1.333f);
            Beep();

            //
            //Chorus
            //
            Console.Write("Hey ");
            Beep("A#", 2);
            Console.WriteLine("now");
            Beep("F#");
            Console.Write("You're ");
            Beep("F#", 4);
            Console.Write("an ");
            Beep("D#", 4);
            Console.Write("All ");
            Beep("F#", 2);
            Console.WriteLine("Star");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 4);
            Console.Write("your ");
            Beep("D#", 4);
            Console.Write("game ");
            Beep("F#", 2);
            Console.WriteLine("on");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Go ");
            Beep("F#", 2);
            Beep("", 2);
            Console.WriteLine("play");
            Beep("A#", 0.8f);

            Console.Write("Hey ");
            Beep("A#", 2);
            Console.WriteLine("now");
            Beep("F#");
            Console.Write("You're ");
            Beep("F#", 4);
            Console.Write("a ");
            Beep("D#", 4);
            Console.Write("rock ");
            Beep("F#", 2);
            Console.WriteLine("star");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 4);
            Console.Write("the ");
            Beep("D#", 4);
            Console.Write("show ");
            Beep("F#", 2);
            Console.WriteLine("on");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 2);
            Beep("", 2);
            Console.WriteLine("paid");
            Beep("A#", 0.8f);

            //Bar 22
            Console.Write("All ");
            Beep("A#");
            Console.Write("that ");
            Beep("C#4");
            Console.Write("glit");
            Beep("B", 2);
            Console.Write("ters ");
            Beep("A#", 2);
            Console.Write("is ");
            Beep("G#", 2);
            Console.Write("go");
            Beep("G#", 2);
            Console.WriteLine("ld");
            Beep("F#", 0.5f);

            Console.Write("Onl");
            Beep("F#", 2);
            Console.Write("y ");
            Beep("F#", 2);
            Console.Write("shoot");
            Beep("G#", 2);
            Console.Write("ing ");
            Beep("F#", 2);
            Console.Write("sta");
            Beep("A#", 2);
            Console.Write("rs ");
            Beep("G#", 0.8f);
            Console.Write("break ");
            Beep("G#", 2);
            Console.Write("the ");
            Beep("F#");
            Console.Write("mo");
            Beep("G#", 2);
            Console.Write("l");
            Beep("A#", 2);
            Console.WriteLine("d");
            Beep("D#", 0.333f);
            //
            //End chorus
            //

            //instrumental solo
            Console.WriteLine("*whistling*");
            for (byte b0 = 0; b0 < 4; b0++)
            {
                Beep("C#5"); Beep("A#4"); Beep("G#4", 2); Beep("F#4", 2); Beep("", 2);
                Beep("A#4"); Beep("B4", 2); Beep("A#4"); Beep("G#4", 2); Beep("F#4", 2); Beep("D#4", 2); Beep("C#4", 2);
            }

            //
            //Chorus ed2
            //
            Console.Write("Hey ");
            Beep("A#", 2);
            Console.WriteLine("now");
            Beep("F#");
            Console.Write("You're ");
            Beep("F#", 4);
            Console.Write("an ");
            Beep("D#", 4);
            Console.Write("All ");
            Beep("F#", 2);
            Console.WriteLine("Star");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 4);
            Console.Write("your ");
            Beep("D#", 4);
            Console.Write("game ");
            Beep("F#", 2);
            Console.WriteLine("on");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Go ");
            Beep("F#", 2);
            Beep("", 2);
            Console.WriteLine("play");
            Beep("A#", 0.8f);

            Console.Write("Hey ");
            Beep("A#", 2);
            Console.WriteLine("now");
            Beep("F#");
            Console.Write("You're ");
            Beep("F#", 4);
            Console.Write("a ");
            Beep("D#", 4);
            Console.Write("rock ");
            Beep("F#", 2);
            Console.WriteLine("star");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 4);
            Console.Write("the ");
            Beep("D#", 4);
            Console.Write("show ");
            Beep("F#", 2);
            Console.WriteLine("on");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 2);
            Beep("", 2);
            Console.WriteLine("paid");
            Beep("A#", 0.8f);

            //Bar 54
            Console.Write("All ");
            Beep("A#");
            Console.Write("that ");
            Beep("C#4");
            Console.Write("glit");
            Beep("B", 2);
            Console.Write("ters ");
            Beep("C#4", 2);
            Console.Write("is ");
            Beep("D#4", 2);
            Console.WriteLine("gold");
            Beep("F#4", 0.4f);

            Console.Write("Onl");
            Beep("F#", 2);
            Console.Write("y ");
            Beep("F#", 2);
            Console.Write("shoot");
            Beep("G#", 2);
            Console.Write("ing ");
            Beep("F#", 2);
            Console.Write("sta");
            Beep("A#", 2);
            Console.WriteLine("rs ");
            Beep("G#", 0.666f);
            //
            //End chorus ed2
            //

            Beep();

            Console.Write("Some");
            Beep("F#");
            Console.Write("bo");
            Beep("C#4", 2);
            Console.Write("dy ");
            Beep("A#", 2);
            Console.Write("once ");
            Beep("A#");
            Console.Write("asked ");
            Beep("G#", 2);
            Console.Write("could ");
            Beep("F#", 2);
            Console.Write("I ");
            Beep("F#", 2);
            Console.Write("spare ");
            Beep("B");
            Console.Write("some ");
            Beep("A#", 2);
            Console.Write("change ");
            Beep("A#", 2);
            Console.Write("for ");
            Beep("G#", 2);
            Console.WriteLine("gas");
            Beep("G#", 2);

            Console.Write("I ");
            Beep("F#", 2);
            Console.Write("need ");
            Beep("G#", 2);
            Console.Write("to ");
            Beep("F#", 2);
            Console.Write("get ");
            Beep("C#4", 2);
            Console.Write("my");
            Beep("A#", 2);
            Console.Write("self ");
            Beep("A#", 2);
            Console.Write("a");
            Beep("G#", 2);
            Console.Write("way ");
            Beep("G#", 2);
            Console.Write("from ");
            Beep("F#", 2);
            Console.Write("this ");
            Beep("F#", 2);
            Console.Write("pla");
            Beep("D#");
            Console.WriteLine("ce");
            Beep("C#", 0.666f);
            Beep();

            Console.Write("I ");
            Beep("C#4", 4);
            Console.Write("said ");
            Beep("C#4", 1.333f);
            Console.Write("yep, ");
            Beep("C#4");
            Console.Write("what ");
            Beep("A#", 4);
            Console.Write("a ");
            Beep("G#", 4);
            Console.Write("con");
            Beep("A#", 2);
            Console.WriteLine("cept");
            Beep("G#");
            Console.Write("I ");
            Beep("G#", 4);
            Console.Write("could ");
            Beep("C#4", 1.333f);
            Console.Write("use ");
            Beep("B", 4);
            Console.Write("a ");
            Beep("A#", 4);
            Console.Write("lit");
            Beep("B", 4);
            Console.Write("tle ");
            Beep("A#", 4);
            Console.Write("fuel ");
            Beep("B", 2);
            Console.Write("my");
            Beep("F#", 2);
            Console.WriteLine("self,");
            Beep("D#", 2);
            Console.Write("And ");
            Beep("C#", 2);
            Console.Write("we ");
            Beep("D#", 2);
            Console.Write("could ");
            Beep("C#", 2);
            Console.Write("all ");
            Beep("C#4");
            Console.Write("use ");
            Beep("A#", 4);
            Console.Write("a ");
            Beep("A#", 4);
            Console.Write("lit");
            Beep("G#", 2);
            Console.Write("tle ");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("cha");
            Beep("G#");
            Console.WriteLine("nge");
            Beep("A#", 0.4f);

            Console.Write("Well, ");
            Beep("C#4", 1.333f);
            Console.Write("the ");
            Beep("C#4", 4);
            Console.Write("years ");
            Beep("C#4", 2);
            Console.Write("start ");
            Beep("C#4", 2);
            Console.Write("com");
            Beep("C#4", 4);
            Console.Write("ing ");
            Beep("C#4", 4);
            Console.Write("and ");
            Beep("C#4", 4);
            Console.Write("they ");
            Beep("C#4", 4);
            Console.Write("don't ");
            Beep("C#4", 2);
            Console.Write("stop ");
            Beep("C#4", 2);
            Console.Write("com");
            Beep("C#4", 4);
            Console.WriteLine("ing,");
            Beep("C#4", 1.333f);

            Console.Write("Fed ");
            Beep("C#4", 2);
            Console.Write("to ");
            Beep("C#4", 4);
            Console.Write("the ");
            Beep("C#4", 4);
            Console.Write("rules ");
            Beep("C#4", 2);
            Console.Write("and ");
            Beep("C#4", 4);
            Console.Write("I ");
            Beep("C#4", 4);
            Console.Write("hit ");
            Beep("C#4", 4);
            Console.Write("the ");
            Beep("C#4", 4);
            Console.Write("ground ");
            Beep("C#4", 2);
            Console.Write("run");
            Beep("D#4", 4);
            Console.WriteLine("ning,");
            Beep("C#4", 1.333f);

            Console.Write("Did");
            Beep("A#", 4);
            Console.Write("n't ");
            Beep("C#4", 4);
            Console.Write("make ");
            Beep("C#4", 2);
            Console.Write("sense ");
            Beep("C#4", 2);
            Console.Write("not ");
            Beep("B", 4);
            Console.Write("to ");
            Beep("B", 4);
            Console.Write("live ");
            Beep("A#", 2);
            Console.Write("for ");
            Beep("A#", 2);
            Console.WriteLine("fun");
            Beep("A#", 1.333f);

            Console.Write("Your ");
            Beep("C#", 4);
            Console.Write("brain ");
            Beep("A#", 2);
            Console.Write("gets ");
            Beep("F#", 2);
            Console.Write("smart ");
            Beep("F#", 2);
            Console.Write("but ");
            Beep("F#", 4);
            Console.Write("your ");
            Beep("D#", 4);
            Console.Write("head ");
            Beep("F#", 2);
            Console.Write("gets ");
            Beep("F#", 2);
            Console.Write("du");
            Beep("D#", 4);
            Console.WriteLine("mb");
            Beep("C#", 1.333f);

            //Bar 69
            Console.Write("So ");
            Beep("A#", 4);
            Console.Write("much ");
            Beep("C#4", 2);
            Console.Write("to ");
            Beep("A#", 4);
            Console.Write("do, ");
            Beep("D#4", 2);
            Console.Write("so ");
            Beep("A#", 4);
            Console.Write("much ");
            Beep("C#4", 2);
            Console.Write("to ");
            Beep("A#", 4);
            Console.WriteLine("see, ");
            Beep("D#4", 2);
            Console.Write("so ");
            Beep("A#", 4);
            Console.Write("what's ");
            Beep("C#4", 2);
            Console.Write("wrong ");
            Beep("B", 2);
            Console.Write("with ");
            Beep("A#", 2);
            Console.Write("tak");
            Beep("G#", 2);
            Console.Write("ing ");
            Beep("G#", 2);
            Console.Write("the ");
            Beep("F#", 4);
            Console.Write("back ");
            Beep("G#", 2);
            Console.WriteLine("streets?");
            Beep("F#", 2);
            Beep("", 1.333f);

            Console.Write("You'll ");
            Beep("C#", 4);
            Console.Write("ne");
            Beep("F#", 4);
            Console.Write("ver ");
            Beep("F#", 4);
            Console.Write("know ");
            Beep("F#", 2);
            Console.Write("if ");
            Beep("F#", 4);
            Console.Write("you ");
            Beep("F#", 4);
            Console.Write("don't ");
            Beep("F#", 2);
            Console.WriteLine("go");
            Beep("F#");
            Beep("", 1.333f);

            Console.Write("You'll ");
            Beep("C#", 4);
            Console.Write("ne");
            Beep("D#4", 4);
            Console.Write("ver ");
            Beep("C#4", 4);
            Console.Write("shine ");
            Beep("C#4", 2);
            Console.Write("if ");
            Beep("C#4", 4);
            Console.Write("you ");
            Beep("C#4", 4);
            Console.Write("don't ");
            Beep("C#4", 2);
            Console.WriteLine("glow");
            Beep("C#4");
            Beep();

            //Bar 73
            //
            //Chorus ed3
            //
            Console.Write("Hey ");
            Beep("A#", 2);
            Console.WriteLine("now");
            Beep("F#");
            Console.Write("You're ");
            Beep("F#", 4);
            Console.Write("an ");
            Beep("D#", 4);
            Console.Write("All ");
            Beep("F#", 2);
            Console.WriteLine("Star");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 4);
            Console.Write("your ");
            Beep("D#", 4);
            Console.Write("game ");
            Beep("F#", 2);
            Console.WriteLine("on");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Go ");
            Beep("F#", 2);
            Beep("", 2);
            Console.WriteLine("play");
            Beep("A#", 0.8f);

            Console.Write("Hey ");
            Beep("A#", 2);
            Console.WriteLine("now");
            Beep("F#");
            Console.Write("You're ");
            Beep("F#", 4);
            Console.Write("a ");
            Beep("D#", 4);
            Console.Write("rock ");
            Beep("F#", 2);
            Console.WriteLine("star");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 4);
            Console.Write("the ");
            Beep("D#", 4);
            Console.Write("show ");
            Beep("F#", 2);
            Console.WriteLine("on");
            Beep("F#", 2);
            Beep("", 2);
            Console.Write("Get ");
            Beep("F#", 2);
            Beep("", 2);
            Console.WriteLine("paid");
            Beep("A#");

            Beep("C#", 2);
            //Bar 54
            Console.Write("All ");
            Beep("A#");
            Console.Write("that ");
            Beep("C#4");
            Console.Write("glit");
            Beep("B", 2);
            Console.Write("ters ");
            Beep("C#4", 2);
            Console.Write("is ");
            Beep("D#4", 2);
            Console.Write("g");
            Beep("F#4", 2);

            Console.Write("o");
            Beep("G#4", 2);
            Console.WriteLine("ld");
            Beep("F#4", 0.666f);

            Console.Write("Onl");
            Beep("F#", 2);
            Console.Write("y ");
            Beep("F#", 2);
            Console.Write("shoot");
            Beep("G#", 2);
            Console.Write("ing ");
            Beep("F#", 2);

            Console.Write("sta");
            Beep("C#4", 2);
            Console.Write("rs ");
            Beep("A#", 0.666f);
            Console.Write("break ");
            Beep("G#", 2);
            Console.Write("the ");
            Beep("F#");
            Console.Write("mo");
            Beep("G#", 2);
            Console.Write("l");
            Beep("A#", 2);
            Console.WriteLine("d");
            Beep("F#", 0.333f);

            Beep("C#", 2);
            //Bar 81
            Console.Write("All ");
            Beep("A#");
            Console.Write("that ");
            Beep("C#4");
            Console.Write("glit");
            Beep("B", 2);
            Console.Write("ters ");
            Beep("C#4", 2);
            Console.Write("is ");
            Beep("D#4", 2);
            Console.Write("g");
            Beep("F#4", 2);

            Console.Write("o");
            Beep("G#4", 2);
            Console.WriteLine("ld");
            Beep("F#4", 0.666f);

            Console.Write("Onl");
            Beep("F#", 2);
            Console.Write("y ");
            Beep("F#", 2);
            Console.Write("shoot");
            Beep("G#", 2);
            Console.Write("ing ");
            Beep("F#", 2);

            Console.Write("sta");
            Beep("C#4", 2);
            Console.Write("rs ");
            Beep("A#", 0.666f);
            Console.Write("break ");
            Beep("G#", 2);
            Console.Write("the ");
            Beep("F#");
            Console.Write("mo");
            Beep("G#", 2);
            Console.Write("l");
            Beep("A#", 2);
            Console.WriteLine("d");
            Beep("D#", 0.286f); // seven halfs

            tempo = initTempo;
        }

        static Thread t;

        public static void play(TrackName a)
        {
            try { t.Abort(); }
            catch (Exception e) { }
            switch (a)
            {
                case TrackName.SMBDie:
                    t = new Thread(new ThreadStart(musicSMBDie));
                    break;
                case TrackName.SMBWin:
                    t = new Thread(new ThreadStart(musicSMBWin));
                    break;
                case TrackName.NSMBBGM:
                    t = new Thread(new ThreadStart(musicNSMBBGM));
                    break;
                case TrackName.SMDDie:
                    t = new Thread(new ThreadStart(musicSMBDieBass));
                    break;
                case TrackName.SMDWin:
                    t = new Thread(new ThreadStart(musicSMDWin));
                    break;
                case TrackName.SMDBGM:
                    t = new Thread(new ThreadStart(musicSMBDieBass));
                    break;
                case TrackName.ReconstructingMoreScience:
                    t = new Thread(new ThreadStart(musicReconstructScience));
                    break;
                case TrackName.YourPreciousMoon:
                    t = new Thread(new ThreadStart(musicPreciousMoon));
                    break;
                case TrackName.MagicRoundabout:
                    t = new Thread(new ThreadStart(musicMagicRnd));
                    break;
                case TrackName.AllStar:
                    t = new Thread(new ThreadStart(musicAllStar));
                    break;
                case TrackName.Umaru:
                    t = new Thread(new ThreadStart(musicUMR));
                    break;
                default:
                    t = new Thread(() => Beep());
                    break;
            }
            t.Start();
        }
    }
}
