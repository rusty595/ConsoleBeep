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

        public enum TrackName { SMBDie, SMBWin, NSMBBGM, SMDDie, SMDWin, SMDBGM, ReconstructingMoreScience, YourPreciousMoon, Stop }

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
                default:
                    t = new Thread(() => Beep());
                    break;
            }
            t.Start();
        }
    }
}
