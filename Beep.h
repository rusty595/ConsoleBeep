#ifndef BEEP_H
#define BEEP_H
#pragma once
#include "Windows.h"
#include <string>
#include "strsafe.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <vector>

//
// This version of Beep.h is from the copypasta branch (also containing karaoke branch versions of songs where available).
// This means this edition of SoundLib contains additional methods for drawing pictures to the console window
// These have only been tested with Microsoft Windows, and work best in Raster Fonts 10x20 (although most other sizes are acceptable) with the default palette
// There are three blocks of print* methods: those designed for code page 437; those that work in both 437 and 850/855; and those used for musicDarkKnight, which work on both and are present in master/karaoke
// This is because code page 850 does not have characters for "left half block" and "right half block", and will display "¦" or "Ì" instead
// To check which code page is installed on your machine, launch cmd and enter "chcp".
// (If the code page it tells you appears to be wrong, e.g. it returns 437 but prints ¦ instead of left half block, run chcp followed by the correct code page, e.g. chcp 850)
//
// usage example:
//	SoundLib::Instance()->play(SoundLib::AllStar); // play automatically puts the song on a new thread, calling a musicX method directly will hang your program until it finishes
//  WaitForSingleObject(SoundLib::t0, INFINITE);
//
//  SoundLib::Instance()->play("notes.txt", SoundLib::C3); // plays from an UltraStar or compatible text file. does not start song on new thread
class SoundLib
{
private: static float mspb;
		 static SoundLib* mInstance;
		 
public:
	static SoundLib* Instance()
	{
		if (!mInstance)
		{
			mInstance = new SoundLib;
		}

		return mInstance;
	}
	SoundLib(){}
	~SoundLib(){}
	enum note { C1, Csharp1, D1, Dsharp1, E1, F1, Fsharp1, G1, Gsharp1, A1, Asharp1, B1, C2, Csharp2, D2, Dsharp2, E2, F2, Fsharp2, G2, Gsharp2, A2, Asharp2, B2, C3, Csharp3, D3, Dsharp3, E3, F3, Fsharp3, G3, Gsharp3, A3, Asharp3, B3, C4, Csharp4, D4, Dsharp4, E4, F4, Fsharp4, G4, Gsharp4, A4, Asharp4, B4, C5, Csharp5, D5, Dsharp5, E5, F5, Fsharp5, G5, Gsharp5, A5, Asharp5, B5, C6, C, Csharp, D, Dsharp, E, F, Fsharp, G, Gsharp, A, Asharp, B, BELL, REST, R };
	static void slBeep(note f = R, float inverseFractionOfQuarterNote = 1.0f)
    {
        int n = 50;
        int l = (int)(mspb / inverseFractionOfQuarterNote);
        switch (f)
            {
				case BELL: std::cout << '\a'; return;
                case R:
                case REST: Sleep(l); return;
                case C1: n = 65; break; // n=2^((x+12)/12)*440 where x = number of semitones from A4
                case Csharp1: n = 69; break;
                case D1: n = 73; break;
                case Dsharp1: n = 78; break;
                case E1: n = 82; break;
                case F1: n = 87; break;
                case Fsharp1: n = 92; break;
                case G1: n = 98; break;
                case Gsharp1: n = 104; break;
                case A1: n = 110; break;
                case Asharp1: n = 117; break;
                case B1: n = 123; break;
                case C2: n = 131; break;
                case Csharp2: n = 139; break;
                case D2: n = 147; break;
                case Dsharp2: n = 156; break;
                case E2: n = 165; break;
                case F2: n = 175; break;
                case Fsharp2: n = 185; break;
                case G2: n = 196; break;
                case Gsharp2: n = 208; break;
                case A2: n = 220; break;
                case Asharp2: n = 233; break;
                case B2: n = 247; break;
				case C:
                case C3: n = 262; break;
				case Csharp:
                case Csharp3: n = 277; break;
				case D:
                case D3: n = 294; break;
				case Dsharp:
                case Dsharp3: n = 311; break;
				case E:
                case E3: n = 330; break;
				case F:
                case F3: n = 349; break;
				case Fsharp:
                case Fsharp3: n = 370; break;
				case G:
                case G3: n = 392; break;
				case Gsharp:
                case Gsharp3: n = 415; break;
				case A:
                case A3: n = 440; break;
				case Asharp:
                case Asharp3: n = 466; break;
				case B:
                case B3: n = 494; break;
                case C4: n = 523; break;
                case Csharp4: n = 554; break;
                case D4: n = 587; break;
                case Dsharp4: n = 622; break;
                case E4: n = 659; break;
                case F4: n = 698; break;
                case Fsharp4: n = 740; break;
                case G4: n = 784; break;
                case Gsharp4: n = 831; break;
                case A4: n = 880; break;
                case Asharp4: n = 932; break;
                case B4: n = 988; break;
                case C5: n = 1047; break;
                case Csharp5: n = 1109; break;
                case D5: n = 1175; break;
                case Dsharp5: n = 1245; break;
                case E5: n = 1319; break;
                case F5: n = 1397; break;
                case Fsharp5: n = 1480; break;
                case G5: n = 1568; break;
                case Gsharp5: n = 1661; break;
                case A5: n = 1760; break;
                case Asharp5: n = 1865; break;
                case B5: n = 1976; break;
                case C6: n = 2093; break;
                default:
					 break;
            }
		Beep(n, l);
    }
	struct param { note f; float inverseFractionOfCrotchet; std::string line; };
	static void slBeep(param slBeepParameters){ std::cout << slBeepParameters.line; slBeep(slBeepParameters.f, slBeepParameters.inverseFractionOfCrotchet); }

	enum TrackName { SMBDie, SMBWin, NSMBBGM, SMDDie, SMDWin, Sonic1GHZ, ReconstructingMoreScience, YourPreciousMoon, MagicRoundabout, AllStar, Umaru, Futurama, PinkPanther, DarkKnightRises, SMBCastleWin, SMBCastleDie, NARussia, NACommonwealth, NAUSA, NALichtenstein, Dangermouse, Flinstones, Stop };

	static DWORD WINAPI musicSMBDie(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 600; slBeep(B3, 4); slBeep(F4, 2); slBeep(F4, 4); slBeep(F4, 3); slBeep(E4, 3); slBeep(D4, 3); slBeep(C4, 4); slBeep(E3, 2); slBeep(E3, 4); slBeep(C3, 2); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicSMBWin(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 600; slBeep(G2, 3); slBeep(C3, 3); slBeep(E3, 3); slBeep(G3, 3); slBeep(C4, 3); slBeep(E4, 3); slBeep(G4, 1); slBeep(E4, 1); slBeep(Gsharp2, 3); slBeep(C3, 3); slBeep(Dsharp3, 3); slBeep(Gsharp3, 3); slBeep(C4, 3); slBeep(Dsharp4, 3); slBeep(Gsharp4, 1); slBeep(Dsharp4, 1); slBeep(Asharp2, 3); slBeep(D3, 3); slBeep(F3, 3); slBeep(Asharp3, 3); slBeep(D4, 3); slBeep(F4, 3); slBeep(Asharp4, 1); slBeep(Asharp4, 3); slBeep(Asharp4, 3); slBeep(Asharp4, 3); slBeep(C5, 0.5f); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicSMBCastleDie(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 550; slBeep(C4, 2); slBeep(R, 2); slBeep(G3, 2); slBeep(R, 2); slBeep(E3, 1); slBeep(A3, 1.5f); slBeep(B3, 1.5f); slBeep(A3, 1.5f); slBeep(Gsharp3, 1.5f); slBeep(Asharp3, 1.5f); slBeep(Gsharp3, 1.5f); slBeep(G3, 4); slBeep(F3, 4); slBeep(G3, 0.5f); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicSMBCastleWin(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 400; slBeep(C4, 2); slBeep(G3, 2); slBeep(E3, 2); slBeep(C4, 2); slBeep(G3, 2); slBeep(E3, 2); slBeep(C4, 0.25f); slBeep(Csharp4, 2); slBeep(Gsharp3, 2); slBeep(F3, 2); slBeep(Csharp4, 2); slBeep(Gsharp3, 2); slBeep(F3, 2); slBeep(Csharp4, 0.25f); slBeep(Dsharp4, 2); slBeep(Asharp3, 2); slBeep(G3, 2); slBeep(Dsharp4, 2); slBeep(Asharp3, 2); slBeep(G3, 2); slBeep(Dsharp4, 0.5f); slBeep(F4, 2); slBeep(F4, 2); slBeep(F4, 2); slBeep(G4, 0.25f); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicNSMBBGM(LPVOID lpParam = 0)
        {
            while (true)
            {
                mspb = 300;
                for (byte b0 = 0; b0 < 2; b0++)
                {
                    slBeep( ); slBeep(E4, 2); slBeep(G4); slBeep(C5, 2); slBeep(A4); slBeep(G4, 2); slBeep(Dsharp4); slBeep(E4, 2);
                    slBeep( ); slBeep(G4, 2); slBeep(Csharp5); slBeep(G4, 2); slBeep(A4); slBeep(Csharp5, 2); slBeep(A4); slBeep(G4, 2);
                    slBeep( ); slBeep(G4, 2); slBeep(A4); slBeep(D5, 2); slBeep(C5); slBeep(A4, 2); slBeep(F4); slBeep(A4, 2);
                    slBeep(F5); slBeep(B4, 2); slBeep(D5); slBeep(F4, 2); slBeep(B4); slBeep(Asharp4, 2); slBeep(A4); slBeep(G4, 2);
                }

                for (byte b0 = 0; b0 < 2; b0++)
                {
                    slBeep(R , 2.0f / 3.0f); slBeep(E); slBeep(F, 2); slBeep(G); slBeep(A, 2); slBeep( ); slBeep(E, 2);
                    slBeep( ); slBeep(G, 2); slBeep( ); slBeep(Gsharp, 2); slBeep(A, 2.0f / 9.0f);
                    slBeep(E); slBeep(F, 2); slBeep(G); slBeep(A, 2); slBeep( ); slBeep(B, 2);
                    slBeep( ); slBeep(B, 2); slBeep( ); slBeep(Asharp, 2); slBeep(A, 2.0f / 9.0f);

                    slBeep(D); slBeep(E, 2); slBeep(F); slBeep(G, 2); slBeep( ); slBeep(D, 2);
                    slBeep( ); slBeep(F, 2); slBeep( ); slBeep(Fsharp, 2); slBeep(G, 2.0f / 9.0f);
                    slBeep(D); slBeep(E, 2); slBeep(F); slBeep(G, 2); slBeep( ); slBeep(A, 2);
                    slBeep( ); slBeep(A, 2); slBeep( ); slBeep(Gsharp, 2); slBeep(G, 2.0f / 9.0f);

                    slBeep(E); slBeep(F, 2); slBeep(G); slBeep(A, 2); slBeep( ); slBeep(E, 2);
                    slBeep( ); slBeep(G, 2); slBeep( ); slBeep(Gsharp, 2); slBeep(A, 2.0f / 9.0f);

                    slBeep(E, 2); slBeep(F, 2.0f / 3.0f); slBeep(G, 8.0f / 9.0f); slBeep(A, 8.0f / 9.0f); slBeep(Asharp, 4.0f / 3.0f);
                    slBeep(A, 0.25f); slBeep(R , 2.0f / 3.0f); slBeep(Gsharp, 2);
                    slBeep(A); slBeep(B, 2); slBeep(C4); slBeep(D4, 2); slBeep(); slBeep(A, 2); slBeep(B); slBeep(C4, 2);
                    slBeep(D4, 1.0f / 3.0f); slBeep(C4, 2.0f / 3.0f); slBeep(D4, 2.0f / 3.0f);
                    slBeep(E4, 2.0f / 3.0f); slBeep(E4); slBeep(C4, 2); slBeep(); slBeep(G, 2); slBeep(); slBeep(B, 2);
                    slBeep(B, 0.4f); slBeep(A, 2.0f / 3.0f); slBeep(R, 2.0f / 3.0f); slBeep(Gsharp, 2);
                    slBeep(A); slBeep(B, 2); slBeep(C4); slBeep(D4, 2); slBeep(); slBeep(A, 2); slBeep(B); slBeep(C4, 2);
                    slBeep(D4, 1.0f / 3.0f); slBeep(E4, 1.0f / 3.0f);
                    slBeep(C4, 1.0f / 6.0f);
                    slBeep(BELL); slBeep(G, 0.5f); slBeep(R, 2); slBeep(BELL); slBeep(G, 2.0f / 3.0f); slBeep(R, 0.5f);
                }

                slBeep(G4); slBeep(A4, 2); slBeep(); slBeep(Dsharp4, 2); slBeep(E4, 2.0f / 3.0f); slBeep(G); slBeep(A, 2);
                slBeep(); slBeep(Dsharp, 2); slBeep(E, 2.0f / 3.0f); slBeep(A); slBeep(G, 2); slBeep(E); slBeep(C, 2);
                slBeep(Asharp2); slBeep(B2, 2); slBeep(Fsharp); slBeep(Asharp2, 2); slBeep(B2); slBeep(Fsharp, 2); slBeep(Asharp2); slBeep(B2, 2);
                slBeep(G, 0.25f); slBeep(R, 0.5f);

                slBeep(F4); slBeep(G4, 2); slBeep(); slBeep(Csharp4, 2); slBeep(D4, 2.0f / 3.0f); slBeep(Asharp); slBeep(B, 2);
                slBeep(); slBeep(F, 2); slBeep(G, 2.0f / 3.0f); slBeep(B); slBeep(G, 2); slBeep(F); slBeep(D, 2);
                slBeep(Dsharp); slBeep(E, 2); slBeep(A); slBeep(Dsharp, 2); slBeep(E); slBeep(A, 2); slBeep(Dsharp); slBeep(E, 2);
                slBeep(A, 0.25f); slBeep(R, 0.5f);

                slBeep(G4); slBeep(A4, 2); slBeep(); slBeep(Dsharp4, 2); slBeep(E4, 2.0f / 3.0f); slBeep(G); slBeep(A, 2);
                slBeep(); slBeep(Dsharp, 2); slBeep(E, 2.0f / 3.0f); slBeep(A); slBeep(G, 2); slBeep(E); slBeep(C, 2);
                slBeep(C5); slBeep(D5, 2); slBeep(); slBeep(Gsharp4, 2); slBeep(A4, 2.0f / 3.0f); slBeep(E4); slBeep(F4, 0.5f);
                slBeep(R, 2.0f / 9.0f);

                slBeep(C5); slBeep(D5, 2); slBeep(); slBeep(Gsharp4, 2); slBeep(A4, 2.0f / 3.0f); slBeep(C5); slBeep(D5, 0.5f);
                slBeep(); slBeep(Gsharp4, 2); slBeep(A4, 2.0f / 3.0f); slBeep(C5); slBeep(D5, 2); slBeep(Gsharp4); slBeep(A4, 2);

                slBeep(C5); slBeep(D5, 2); slBeep(); slBeep(G4, 2); slBeep(A4, 2.0f / 3.0f); slBeep(C5); slBeep(D5, 0.5f);
                slBeep(); slBeep(G4, 2); slBeep(A4, 2.0f / 3.0f); slBeep(C5); slBeep(D5, 2); slBeep(G4); slBeep(A4, 2);

                slBeep(Dsharp4); slBeep(E4, 2); slBeep(A4); slBeep(Dsharp4, 2); slBeep(E4); slBeep(A4, 2); slBeep(Dsharp4); slBeep(E4, 2); slBeep(A4); slBeep(Dsharp4, 2); slBeep(E4); slBeep(G4, 2); slBeep(Dsharp4); slBeep(E4, 2); slBeep(C4); slBeep(A, 2); slBeep(C4, 0.25f);
                slBeep(G1, 2.0f / 3.0f); slBeep(G1, 2.0f / 3.0f); slBeep(A1, 2.0f / 3.0f); slBeep(B1, 2.0f / 3.0f);
            }
        }
	static DWORD WINAPI musicSMBDieBass(LPVOID lpParam = 0) { mspb = 600; slBeep(G2, 2); slBeep(R, 4); slBeep(G2, 4); slBeep(G2, 3); slBeep(A2, 3); slBeep(B2, 3); slBeep(C3, 2); slBeep(G2, 2); slBeep(C2, 2); return 0; }

	static DWORD WINAPI musicSMDWin(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 350; slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3); slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3); slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3, 0.5f); slBeep(C5, 2); slBeep(B4, 2); slBeep(G4, 2); slBeep(A4, 0.2f); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicS1GHZ(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; mspb = 400;
		slBeep(A4, 4); slBeep(F4, 4); slBeep(A4, 4); slBeep(F4, 4);
		slBeep(B4, 4); slBeep(G4, 4); slBeep(B4, 4); slBeep(G4, 4);
		slBeep(C5, 4); slBeep(A4, 4); slBeep(C5, 4); slBeep(A4, 4);
		slBeep(D5, 4); slBeep(B4, 4); slBeep(D5, 4); slBeep(B4, 4);

		slBeep(B); slBeep(R, 2); slBeep(A, 0.666f); slBeep(B);
		slBeep(R, 2); slBeep(A, 0.666f); slBeep(B); slBeep(A);
		slBeep(C4); slBeep(R, 2); slBeep(B, 0.666f); slBeep(A, 0.2f);

		slBeep(A); slBeep(R, 2); slBeep(B, 0.666f); slBeep(C4);
		slBeep(A); slBeep(R, 2); slBeep(B, 0.666f); slBeep(C4);
		slBeep(C4); slBeep(R, 2); slBeep(B, 0.154f);
		while (true)
		{
			slBeep(R, 0.5f); slBeep(C4, 2); slBeep(A); slBeep(C4, 2);
			slBeep(B); slBeep(C4, 2); slBeep(B); slBeep(G, 0.333f); slBeep(G, 2); slBeep(E4, 2); slBeep(D4); slBeep(C4, 2);
			slBeep(B); slBeep(C4, 2); slBeep(B); slBeep(G, 0.286f); slBeep(C4, 2); slBeep(A); slBeep(C4, 2);
			slBeep(B); slBeep(C4, 2); slBeep(B); slBeep(G, 0.333f); slBeep(A, 2); slBeep(A, 2); slBeep(F); slBeep(A, 2);
			slBeep(G); slBeep(A, 2); slBeep(G); slBeep(C, 0.286f); slBeep(C4, 2); slBeep(A); slBeep(C4, 2);
			slBeep(B); slBeep(C4, 2); slBeep(B); slBeep(G, 0.333f); slBeep(G, 2); slBeep(E4, 2); slBeep(D4); slBeep(C4, 2);
			slBeep(B); slBeep(C4, 2); slBeep(B); slBeep(G, 0.286f); slBeep(C4, 2); slBeep(A); slBeep(C4, 2);
			slBeep(B); slBeep(C4, 2); slBeep(B); slBeep(G, 0.333f); slBeep(A, 2); slBeep(A, 2); slBeep(F); slBeep(A, 2);
			slBeep(G); slBeep(A, 2); slBeep(G); slBeep(C, 0.286f);

			slBeep(D4, 0.154f); slBeep(C4, 2); slBeep(D4, 2); slBeep(E4, 0.143f); slBeep(C4, 2); slBeep(C4, 2); slBeep(E4, 2);
			slBeep(Dsharp4, 0.154f); slBeep(C4, 2); slBeep(Dsharp4, 2); slBeep(D4, 0.25f); slBeep(E4); slBeep(E4, 2); slBeep(F4, 2); slBeep(E4, 2); slBeep(G4, 2); slBeep(E4, 2); slBeep(E4, 2); slBeep(C4, 2);
		}
	}

	static DWORD WINAPI musicReconstructScience(LPVOID lpParam = 0)
        {
            float previousmspb = mspb; mspb = 600;
            for (byte b0 = 0; b0 < 2; b0++) // this loop pitched up one octave due to poor fish handling
            {
            slBeep(F3, 2); slBeep(C4, 2); slBeep(G3, 2); slBeep(Gsharp3, 2); slBeep(F3, 2); slBeep(C4, 2); slBeep(G3, 2); slBeep(Asharp3, 2);
            slBeep(F3, 2); slBeep(C4, 2); slBeep(G3, 2); slBeep(Gsharp3, 2); slBeep(Asharp3, 2); slBeep(Gsharp3, 2); slBeep(G3, 2); slBeep(Gsharp3, 2);
            }
            for (byte b0 = 0; b0 < 2; b0++)
            {
            slBeep(F); slBeep(C4); slBeep(Gsharp); slBeep(Asharp); slBeep(G); slBeep(Gsharp); slBeep(F); slBeep(E);
            slBeep(F); slBeep(C4); slBeep(Gsharp); slBeep(Asharp); slBeep(Csharp4); slBeep(G); slBeep(Asharp); slBeep(E);
            }
            for (byte b0 = 0; b0 < 2; b0++)
            {
                slBeep(F4); slBeep(C5); slBeep(Gsharp4); slBeep(Asharp4); slBeep(G4); slBeep(Gsharp4); slBeep(F4); slBeep(E4);
                slBeep(F4); slBeep(C5); slBeep(Gsharp4); slBeep(Asharp4); slBeep(Csharp5); slBeep(G4); slBeep(Asharp4); slBeep(E4);
            }
            for (byte b0 = 0; b0 < 2; b0++)
            {
                slBeep(F4, 2); slBeep(C5, 2); slBeep(G4, 2); slBeep(Gsharp4, 2); slBeep(F4, 2); slBeep(C5, 2); slBeep(G4, 2); slBeep(Asharp4, 2);
                slBeep(F4, 2); slBeep(C5, 2); slBeep(G4, 2); slBeep(Gsharp4, 2); slBeep(Asharp4, 2); slBeep(Gsharp4, 2); slBeep(G4, 2); slBeep(Gsharp4, 2);
            }
            slBeep(F4, 0.5f); slBeep(F4, 0.5f); slBeep(F4, 0.25f);
            mspb = previousmspb;
			return 0;
        }
	static DWORD WINAPI musicPreciousMoon(LPVOID lpParam = 0)
        {
            float previousmspb = mspb; mspb = 600;
            slBeep(F4, 2);
            for (byte b0 = 0; b0 < 14; b0++)
            {
                slBeep(E4, 2); slBeep(F4, 2); slBeep(D4, 2); slBeep(F4, 2);
            }
            slBeep(D4, 2); slBeep(Asharp4, 2); slBeep(G4, 2); slBeep(A4, 2); slBeep(Csharp5, 2); slBeep(A4, 2); slBeep(Asharp4, 2); slBeep(G4, 2);
            for (byte b0 = 0; b0 < 3; b0++)
            {
                slBeep(D4, 2); slBeep(A4, 2); slBeep(G4, 2); slBeep(A4, 2); slBeep(F4, 2); slBeep(G4, 2); slBeep(E4, 2); slBeep(F4, 2);
            }
            slBeep(D4, 2); slBeep(Asharp4, 2); slBeep(G4, 2); slBeep(A4, 2); slBeep(Csharp5, 2); slBeep(A4, 2); slBeep(Asharp4, 2); slBeep(G4, 0.125f);
            mspb = previousmspb;
			return 0;
        }

	static DWORD WINAPI musicMagicRnd(LPVOID lpParam = 0)
    {
        float previousmspb = mspb; mspb = 500;
        for (byte b0 = 0; b0 < 2; b0++)
        {
            slBeep(C5); slBeep(C5, 2); slBeep(C5, 2); slBeep(G4); slBeep(G4);
            slBeep(A4); slBeep(A4, 2); slBeep(A4, 2); slBeep(F4, 0.5f);
            slBeep(Asharp4); slBeep(Asharp4, 2); slBeep(Asharp4, 2); slBeep(F4); slBeep(F4);
            slBeep(B4); slBeep(B4, 2); slBeep(B4, 2); if (b0<1) slBeep(G4, 0.5f);
        }
        slBeep(G4); slBeep(G4); slBeep(C5, 0.2f);
        mspb = previousmspb;
		return 0;
    }
	static DWORD WINAPI musicUMR(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; mspb = 600;
		slBeep(Fsharp, 4); slBeep(Fsharp, 4); slBeep(Fsharp, 2); slBeep(G, 2);
		slBeep(A, 1.666f); slBeep(A, 1.666f); slBeep(B, 2); slBeep(A, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(G, 2);
		slBeep(A, 2); slBeep(A, 4); slBeep(A, 1.666f); slBeep(B, 2); slBeep(A); slBeep(R, 2); slBeep(A, 2);
		slBeep(D); slBeep(R, 2); slBeep(A, 2); slBeep(D); slBeep(R, 2); slBeep(A, 2);
		slBeep(B2, 2); slBeep(Csharp, 2); slBeep(D, 2); slBeep(Fsharp, 2); slBeep(Fsharp, 1.666f); slBeep(E, 4); slBeep(E);
		slBeep(A, 1.666f); slBeep(A, 1.666f); slBeep(B, 2); slBeep(A, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(G, 2);
		slBeep(A, 1.666f); slBeep(D4, 1.666f); slBeep(Csharp4, 2); slBeep(D4); slBeep(R, 2); slBeep(D, 2);
		slBeep(B2, 2); slBeep(Csharp, 2); slBeep(D, 2); slBeep(Fsharp, 2); slBeep(E, 0.666f); slBeep(D, 2);
		slBeep(D, 0.5f); slBeep(D5); slBeep(D5); slBeep(D5); slBeep(D5); slBeep(D5, 4); slBeep(Fsharp5, 2); slBeep(Fsharp5, 4); slBeep(E5, 2); slBeep(D5, 2); slBeep(D5); slBeep(D5); slBeep(D5); slBeep(D5); slBeep(G4, 1.666f); slBeep(Fsharp4, 1.666f); slBeep(G4, 2); slBeep(A4); slBeep();

		slBeep(D, 1.666f); slBeep(D, 1.666f); slBeep(Csharp, 2); slBeep(D); slBeep(R, 2); slBeep(D, 4); slBeep(E, 4);
		slBeep(Fsharp, 1.666f); slBeep(E, 1.666f); slBeep(D, 2); slBeep(BELL); slBeep(E); slBeep(BELL); slBeep(R, 2); slBeep(D, 4); slBeep(E, 4);
		slBeep(G, 1.666f); slBeep(G, 1.666f); slBeep(Fsharp, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(E, 2); slBeep(Fsharp, 2);
		slBeep(E, 1.666f); slBeep(E, 1.666f); slBeep(Fsharp, 2); slBeep(Fsharp); slBeep(R, 2); slBeep(B2, 4); slBeep(Csharp, 4);
		slBeep(D, 1.666f); slBeep(BELL); slBeep(D, 1.666f); slBeep(BELL); slBeep(Csharp, 2); slBeep(BELL); slBeep(D); slBeep(BELL); slBeep(R, 2); slBeep(D, 4); slBeep(E, 4);
		slBeep(Fsharp, 1.666f); slBeep(E, 1.666f); slBeep(D, 2); slBeep(E); slBeep(R, 2); slBeep(D, 4); slBeep(E, 4);
		slBeep(G, 1.666f); slBeep(G, 1.666f); slBeep(Fsharp, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(E, 2); slBeep(Fsharp, 2);
		slBeep(D); slBeep(A); slBeep(D); slBeep(B, 8); slBeep(A, 8); slBeep(B, 8); slBeep(A, 8); slBeep(B, 8); slBeep(A, 8); slBeep(G, 4);
		//Bar 26
		slBeep(Fsharp, 1.666f); slBeep(Fsharp, 4); slBeep(Fsharp, 4); slBeep(Fsharp, 4); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(E, 2);
		slBeep(Fsharp, 4); slBeep(G, 4); slBeep(Fsharp, 4); slBeep(G, 4); slBeep(Fsharp, 4); slBeep(D, 4); slBeep(B2); slBeep(B2, 2);
		slBeep(Fsharp, 1.666f); slBeep(Fsharp, 4); slBeep(Fsharp, 4); slBeep(Fsharp, 4); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(E, 2);
		slBeep(E, 1.666f); slBeep(E, 4); slBeep(E, 2); slBeep(E, 2); slBeep(D, 2); slBeep(E, 2);
		slBeep(Fsharp, 1.666f); slBeep(G, 4); slBeep(Fsharp, 4); slBeep(G, 4); slBeep(Fsharp); slBeep(D, 4); slBeep(E, 4);
		slBeep(Fsharp, 1.666f); slBeep(Fsharp, 4); slBeep(Fsharp, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(E, 2);
		//Bar 31
		slBeep(Fsharp, 4); slBeep(G, 4); slBeep(Fsharp, 4); slBeep(G, 4); slBeep(Fsharp, 4); slBeep(Csharp4, 4);
		slBeep(B); slBeep(B, 2); slBeep(A, 2);
		slBeep(G, 1.666f); slBeep(G, 1.666f); slBeep(G, 2); slBeep(A, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(G, 2);
		slBeep(A, 1.666f); slBeep(Fsharp, 1.666f); slBeep(A, 2); slBeep(B); slBeep(B, 2); slBeep(A, 2);
		slBeep(G, 0.666f); slBeep(G); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(G, 2);
		slBeep(A, 0.5f);

		slBeep(R, 2);

		slBeep(Fsharp, 4); slBeep(Fsharp, 4); slBeep(Fsharp, 2); slBeep(G, 2);
		slBeep(A, 1.666f); slBeep(A, 2); slBeep(A, 4); slBeep(B, 2); slBeep(A, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(G, 2);
		slBeep(A, 1.666f); slBeep(A, 1.666f); slBeep(B, 2); slBeep(A); slBeep(R, 2); slBeep(A, 2);
		slBeep(D); slBeep(R, 2); slBeep(A, 2); slBeep(D); slBeep(R, 2); slBeep(D, 2);
		slBeep(B2, 2); slBeep(Csharp, 2); slBeep(D, 2); slBeep(Fsharp, 2); slBeep(Fsharp, 1.666f); slBeep(E, 4); slBeep(E);
		slBeep(A, 1.666f); slBeep(A, 1.666f); slBeep(B, 2); slBeep(A, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(G, 2);
		slBeep(A, 1.666f); slBeep(D4, 1.666f); slBeep(Csharp4, 2); slBeep(D4); slBeep(R, 2); slBeep(A, 2);
		slBeep(D); slBeep(R, 2); slBeep(A, 2); slBeep(D); slBeep(R, 2); slBeep(D, 2);
		slBeep(B2, 2); slBeep(Csharp, 2); slBeep(D, 2); slBeep(Fsharp, 2); slBeep(Fsharp); slBeep(E, 2); slBeep(D, 2);
		slBeep(D); slBeep(R, 2); slBeep(D, 2); slBeep(Csharp, 2); slBeep(E, 2); slBeep(B, 2);
		slBeep(A, 1.666f); slBeep(Fsharp, 1.666f); slBeep(A, 2); slBeep(D4); slBeep(R, 2); slBeep(D, 2);
		slBeep(Fsharp, 2); slBeep(G, 2); slBeep(Fsharp, 2); slBeep(G, 2); slBeep(A, 2); slBeep(D, 2); slBeep(E, 2); slBeep(E, 2);
		slBeep(D, 0.5f); slBeep(R, 2); slBeep(Csharp5, 2); slBeep(D5, 2); slBeep(E5, 2);
		slBeep(Fsharp5, 4); slBeep(G5, 4); slBeep(Fsharp5); slBeep(D5, 0.666f); slBeep();
		//Bar 50
		slBeep(Fsharp4); slBeep(G4); slBeep(Gsharp4); slBeep(A4); slBeep(Asharp4); slBeep(B4); slBeep(C5); slBeep(Csharp5); slBeep(D5, 0.5f); slBeep(R, 0.5f);
		slBeep(D, 1.666f); slBeep(C, 1.666f); slBeep(Csharp, 2); slBeep(D);
		mspb = previousmspb;
		return 0;
	}
	static DWORD WINAPI musicFut(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; mspb = 600;
		slBeep(E4, 0.666f); slBeep(E4, 2); slBeep(A4); slBeep(Gsharp4);
		slBeep(D4, 0.666f); slBeep(D4, 2); slBeep(Fsharp4); slBeep(E4);
		for (byte b0 = 0; b0 < 2; b0++)
		{
			slBeep(E4); slBeep(E4); slBeep(R, 2); slBeep(A4, 2); slBeep(A4);
			slBeep(D4); slBeep(D4); slBeep(R, 2); if (b0 < 1) { slBeep(E4, 2); slBeep(E4); }
			else { slBeep(G4, 2); slBeep(G4, 2); slBeep(Fsharp4, 2); }
		}
		slBeep(E4, 0.666f); slBeep(E4, 2); slBeep(A4); slBeep(Gsharp4);
		slBeep(D4, 0.666f); slBeep(D4, 2); slBeep(Fsharp4); slBeep(E4);
		slBeep(E4, 0.666f); slBeep(E4, 2); slBeep(A4); slBeep(Gsharp4);
		slBeep(B4, 0.666f); slBeep(B4, 2); slBeep(G4, 2); slBeep(G4, 2); slBeep(Fsharp4, 2); slBeep(Fsharp4, 2);

		slBeep(E1, 2); slBeep(D2, 2); slBeep(E2, 2); slBeep(A1); slBeep(D2, 2); slBeep(E2, 2); slBeep(B1, 2);

		slBeep(R, 2); slBeep(Gsharp4, 4); slBeep(Gsharp4, 4); slBeep(Gsharp4, 2); slBeep(Dsharp4, 2); slBeep(Dsharp4, 2); slBeep(B3, 2); slBeep(B3, 2); slBeep(Gsharp3, 2); slBeep(BELL); slBeep(R);
		mspb = previousmspb;
		return 0;
	}
	static DWORD WINAPI musicPP(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; mspb = 660;
		slBeep(Gsharp2, 4); slBeep(A2, 1.666f); slBeep(Asharp2, 4); slBeep(B2, 0.2f);
		slBeep(Gsharp2, 4); slBeep(A2, 1.666f); slBeep(Asharp2, 4); slBeep(B2, 0.2f);
		slBeep(Asharp2, 4); slBeep(A2, 1.666f); slBeep(Gsharp2, 4); slBeep(G2, 0.2f);
		slBeep(Gsharp2, 4); slBeep(A2, 1.666f); slBeep(Asharp2, 4); slBeep(B2, 0.2f);
		slBeep(R, 1.666f); slBeep(Dsharp, 4);
		while (true)
		{
			slBeep(E); slBeep(R, 1.666f); slBeep(Fsharp, 4); slBeep(G); slBeep(R, 1.666f); slBeep(Dsharp, 4);
			slBeep(E, 1.666f); slBeep(Fsharp, 4); slBeep(G, 1.666f); slBeep(C4, 4); slBeep(B, 1.666f); slBeep(E, 4); slBeep(G, 1.666f); slBeep(B, 4);
			slBeep(Asharp, 0.421f); slBeep(A, 2.666f); slBeep(G, 4); slBeep(E, 2.666f); slBeep(D, 2.666f); slBeep(E, 0.308f); slBeep(R, 1.666f); slBeep(Dsharp, 4);
			slBeep(E); slBeep(R, 1.666f); slBeep(Fsharp, 4); slBeep(G); slBeep(R, 1.666f); slBeep(Dsharp, 4);
			slBeep(E, 1.666f); slBeep(Fsharp, 4); slBeep(G, 1.666f); slBeep(C4, 4); slBeep(B, 1.666f); slBeep(E, 4); slBeep(G, 1.666f); slBeep(E4, 4);
			slBeep(Dsharp4, 0.129f); slBeep(Dsharp, 4);
			//bar 18
			slBeep(E, 0.571f); slBeep(Fsharp, 4); slBeep(G, 0.571f); slBeep(Dsharp, 4);
			slBeep(E, 1.666f); slBeep(Fsharp, 4); slBeep(G, 1.666f); slBeep(C4, 4); slBeep(B, 1.666f); slBeep(E, 4); slBeep(G, 1.666f); slBeep(B, 4);
			slBeep(Asharp, 0.421f); slBeep(A, 2.666f); slBeep(G, 4); slBeep(E, 2.666f); slBeep(D, 2.666f); slBeep(E, 0.444f); slBeep(R, 0.333f);
			slBeep(E4, 1.666f); slBeep(D4, 4); slBeep(B, 1.666f); slBeep(A, 4); slBeep(G, 1.666f); slBeep(E, 4);
			for (byte b0 = 0; b0 < 4; b0++)
				slBeep(Asharp, 1.666f); slBeep(A, 4);
			slBeep(G, 2.666f); slBeep(E, 2.666f); slBeep(D, 4); slBeep(E, 2); slBeep(E, 0.222f); slBeep(R, 0.5f);
			slBeep(G, 2.666f); slBeep(E, 2.666f); slBeep(D, 4); slBeep(E, 2); slBeep(E, 0.222f); slBeep(R, 0.5f);
			slBeep(G, 2.666f); slBeep(E, 2.666f); slBeep(D, 4); slBeep(E, 2); slBeep(E, 0.222f); slBeep(R, 0.571f); slBeep(Dsharp, 4);
		}
	}
	static DWORD WINAPI musicDM(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; mspb = 380;

		slBeep(E, 1.33f); slBeep(E, 4); slBeep(E, 2.66f); slBeep(E, 1.6f); slBeep(E, 1.33f); slBeep(E, 4); slBeep(R, 2.66f); slBeep(E, 1.6f);
		slBeep(Gsharp, 1.33f); slBeep(Gsharp, 4); slBeep(Gsharp, 2.66f); slBeep(Gsharp, 1.6f); slBeep(Gsharp, 1.33f); slBeep(Gsharp, 4); slBeep(R, 2.66f); slBeep(Gsharp, 1.6f);
		slBeep(B, 1.33f); slBeep(B, 4); slBeep(B, 2.66f); slBeep(B, 1.6f); slBeep(B, 1.33f); slBeep(B, 4); slBeep(R, 2.66f); slBeep(B, 1.6f);
		slBeep(D4, 0.25f);

		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(C4); slBeep(D4); slBeep(C4); slBeep();
		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(F, 0.5f); slBeep(C4, 0.5f);
		slBeep(E4, 0.33f); slBeep();
		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(F, 0.5f); slBeep(C4, 0.5f);
		slBeep(A4, 0.166f); slBeep(R, 0.5f);

		slBeep(); slBeep(R, 0.5f); slBeep(R, 2); slBeep(R, 4); slBeep(F4, 4);
		slBeep(F4, 1.66f); slBeep(Csharp4, 4); slBeep(Csharp4, 1.66f); slBeep(Asharp, 4); slBeep(Asharp); slBeep();
		slBeep(); slBeep(R, 0.5f); slBeep(R, 2); slBeep(R, 4); slBeep(Fsharp4, 4);
		slBeep(Fsharp4, 1.66f); slBeep(D4, 4); slBeep(D4, 1.66f); slBeep(B, 4); slBeep(B); slBeep();

		slBeep(E4, 1.33f); slBeep(E4, 4); slBeep(E4, 2.66f); slBeep(E4, 1.6f); slBeep(E4, 1.33f); slBeep(E4, 4); slBeep(R, 2.66f); slBeep(E4, 1.6f);
		slBeep(F4, 1.33f); slBeep(F4, 4); slBeep(F4, 2.66f); slBeep(F4, 1.6f); slBeep(F4, 1.33f); slBeep(F4, 4); slBeep(R, 2.66f); slBeep(D4, 1.6f);
		slBeep(E4); slBeep(R, 2.66f); slBeep(B, 1.6f); slBeep(E4, 0.166f);

		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(F, 0.5f); slBeep(C4, 0.5f);
		slBeep(E4, 0.33f); slBeep();
		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(R, 2); slBeep(E4, 2); slBeep(R, 2); slBeep(D4, 2); slBeep(C4); slBeep(A);
		slBeep(F, 0.5f); slBeep(C4, 0.5f);
		slBeep(A4, 0.166f); slBeep(R, 0.5f);

		slBeep(); slBeep(R, 0.5f); slBeep(R, 2); slBeep(R, 4); slBeep(F4, 4);
		slBeep(F4, 1.66f); slBeep(Csharp4, 4); slBeep(Csharp4, 1.66f); slBeep(Asharp, 4); slBeep(Asharp); slBeep();
		slBeep(R, 2); slBeep(F4, 2); slBeep(R, 2); slBeep(Dsharp4, 2); slBeep(Csharp4); slBeep(Asharp);
		slBeep(R, 2); slBeep(F4, 2); slBeep(R, 2); slBeep(Dsharp4, 2); slBeep(Csharp4); slBeep(Asharp);
		slBeep(Fsharp, 0.5f); slBeep(Csharp4, 0.5f);
		slBeep(F4, 0.33f); slBeep();
		slBeep(R, 2); slBeep(F4, 2); slBeep(R, 2); slBeep(Dsharp4, 2); slBeep(Csharp4); slBeep(Asharp);
		slBeep(R, 2); slBeep(F4, 2); slBeep(R, 2); slBeep(Dsharp4, 2); slBeep(Csharp4); slBeep(Asharp);
		slBeep(Fsharp, 0.5f); slBeep(Csharp4, 0.5f);
		slBeep(Asharp4, 0.166f); slBeep(R, 0.5f);

		slBeep(); slBeep(R, 0.5f); slBeep(R, 2); slBeep(R, 4); slBeep(Fsharp4, 4);
		slBeep(Fsharp4, 1.66f); slBeep(D4, 4); slBeep(D4, 1.66f); slBeep(B, 4); slBeep(B); slBeep();
		slBeep(); slBeep(R, 0.5f); slBeep(R, 2); slBeep(R, 4); slBeep(G4, 4);
		slBeep(G4, 1.66f); slBeep(Dsharp4, 4); slBeep(Dsharp4, 1.66f); slBeep(C4, 4); slBeep(C4); slBeep();

		slBeep(F4, 1.33f); slBeep(F4, 4); slBeep(F4, 2.66f); slBeep(F4, 1.6f); slBeep(F4, 1.33f); slBeep(F4, 4); slBeep(R, 2.66f); slBeep(F4, 1.6f);
		slBeep(Fsharp4, 1.33f); slBeep(Fsharp4, 4); slBeep(Fsharp4, 2.66f); slBeep(Fsharp4, 1.6f); slBeep(Fsharp4, 1.33f); slBeep(Fsharp4, 4); slBeep(R, 2.66f); slBeep(Dsharp4, 1.6f);
		slBeep(F4); slBeep(R, 2.66f); slBeep(C4, 1.6f); slBeep(F4, 0.166f);

		mspb = previousmspb;
		return 0;
	}

	// passing this an int* to change the mspb
	static DWORD WINAPI musicStateAnthemOfTheRussianFederation(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; if (lpParam != 0) mspb = *(int*)lpParam;

		slBeep(Dsharp4, 0.5f); slBeep(R, 2); slBeep(Asharp3, 2);
		slBeep(Dsharp4, 1); slBeep(Asharp3, 1.33f); slBeep(C4, 4); slBeep(D4, 1); slBeep(G3, 2); slBeep(G3, 2);
		slBeep(C4, 1); slBeep(Asharp3, 1.33f); slBeep(Gsharp3, 4); slBeep(Asharp3, 1); slBeep(Dsharp3, 2); slBeep(Dsharp3, 2);
		slBeep(F3, 1); slBeep(F3, 1.33f); slBeep(G3, 4); slBeep(Gsharp3, 1); slBeep(Gsharp3, 2); slBeep(Asharp3, 2);
		slBeep(C4, 1); slBeep(D4, 2); slBeep(Dsharp4, 2); slBeep(F4, 0.66f); slBeep(Asharp3, 2);
		slBeep(G4, 1); slBeep(F4, 1.33f); slBeep(Dsharp4, 4); slBeep(F4, 1); slBeep(D4, 2); slBeep(Asharp3, 2);
		slBeep(Dsharp4, 1); slBeep(D4, 1.33f); slBeep(C4, 4); slBeep(D4, 1); slBeep(G3, 2); slBeep(G3, 2);
		slBeep(C4, 1); slBeep(Asharp3, 1.33f); slBeep(Gsharp3, 4); slBeep(Asharp3, 1); slBeep(Dsharp3, 1.33f); slBeep(Dsharp3, 4);
		slBeep(Dsharp4, 1); slBeep(D4, 1.33f); slBeep(C4, 4); slBeep(Asharp3, 2); slBeep(D4, 2); slBeep(Dsharp4, 2); slBeep(F4, 2);
		slBeep(G4, 0.5f); slBeep(Asharp4, 2); slBeep(Dsharp4, 2); slBeep(D4, 2); slBeep(Dsharp4, 2);
		slBeep(F4, 2); slBeep(Asharp4, 4); slBeep(Asharp4, 8); slBeep(Asharp4, 8); slBeep(Asharp4, 2); slBeep(Asharp3, 2); slBeep(Asharp3, 2); slBeep(D4, 2); slBeep(Dsharp4, 2); slBeep(F4, 2);
		slBeep(Dsharp4, 0.5f); slBeep(G4, 2); slBeep(C4, 2); slBeep(Asharp3, 2); slBeep(C4, 2);
		slBeep(D4, 2); slBeep(G4, 4); slBeep(G4, 8); slBeep(G4, 8); slBeep(G4, 2); slBeep(G3, 2); slBeep(G3, 2); slBeep(Asharp3, 2); slBeep(C4, 2); slBeep(D4, 2);
		slBeep(Dsharp4, 1); slBeep(C4, 1.33f); slBeep(D4, 4); slBeep(Dsharp4, 1); slBeep(C4, 1.33f); slBeep(D4, 4);
		slBeep(Dsharp4, 1); slBeep(C4, 2); slBeep(Dsharp4, 2); slBeep(Gsharp4, 2); slBeep(Gsharp4, 4); slBeep(Gsharp4, 8); slBeep(Gsharp4, 8); slBeep(Gsharp4, 2); slBeep(Gsharp4, 2);
		slBeep(Gsharp4, 0.5f); slBeep(G4, 2); slBeep(F4, 2); slBeep(Dsharp4, 2); slBeep(F4, 2);
		slBeep(G4, 0.66f); slBeep(Dsharp4, 2); slBeep(Dsharp4, 2); slBeep(Asharp3, 4); slBeep(Asharp3, 4); slBeep(Asharp3, 2); slBeep(Asharp3, 2);
		slBeep(F4, 1); slBeep(C4, 1); slBeep(Dsharp4, 2); slBeep(D4, 2); slBeep(C4, 2); slBeep(D4, 2);
		slBeep(Dsharp4, 0.66f); slBeep(C4, 2); slBeep(C4, 2);  slBeep(G3, 2); slBeep(Asharp2, 2); slBeep(G3, 2);
		slBeep(Dsharp4, 1); slBeep(D4, 1.33f); slBeep(C4, 4); slBeep(Asharp3, 1); slBeep(Dsharp3, 2); slBeep(Dsharp3, 2);
		slBeep(Dsharp4, 1); slBeep(D4, 2); slBeep(Dsharp3, 4); slBeep(C4, 4); slBeep(Asharp3, 1); slBeep(Gsharp3, 2); slBeep(Asharp3, 2);
		slBeep(Dsharp4, 1); slBeep(Asharp3, 1.33f); slBeep(C4, 4); slBeep(D4, 1); slBeep(G3, 2); slBeep(G3, 2);
		slBeep(C4, 1); slBeep(Asharp3, 1.33f); slBeep(Gsharp3, 4); slBeep(Asharp3, 1); slBeep(Dsharp3, 2); slBeep(Dsharp3, 2);
		slBeep(F3, 1); slBeep(F3, 1.33f); slBeep(G3, 4); slBeep(Gsharp3, 1); slBeep(Gsharp3, 2); slBeep(Asharp3, 2);
		slBeep(C4, 1); slBeep(D4, 2); slBeep(Dsharp4, 2); slBeep(F4, 0.66f); slBeep(Asharp3, 2);
		slBeep(G4, 1); slBeep(F4, 1.33f); slBeep(Dsharp4, 4); slBeep(F4, 1); slBeep(D4, 2); slBeep(Asharp3, 2);
		slBeep(Dsharp4, 1); slBeep(D4, 1.33f); slBeep(C4, 4); slBeep(D4, 1); slBeep(G3, 2); slBeep(G3, 2);
		slBeep(C4, 1); slBeep(Asharp3, 1.33f); slBeep(Gsharp3, 4); slBeep(Asharp3, 1); slBeep(Dsharp3, 1.33f); slBeep(Dsharp3, 4);
		slBeep(Dsharp4, 1); slBeep(D4, 1.33f); slBeep(C4, 4); slBeep(Asharp3, 2); slBeep(D4, 2); slBeep(Dsharp4, 2); slBeep(F4, 2);
		slBeep(G4, 0.5f); slBeep(Asharp4, 2); slBeep(Dsharp4, 2); slBeep(D4, 2); slBeep(Dsharp4, 2);
		slBeep(F4, 2); slBeep(Asharp4, 4); slBeep(Asharp4, 8); slBeep(Asharp4, 8); slBeep(Asharp4, 2); slBeep(Asharp3, 2); slBeep(Asharp3, 2); slBeep(D4, 2); slBeep(Dsharp4, 2); slBeep(F4, 2);
		slBeep(Dsharp4, 0.5f); slBeep(G4, 2); slBeep(C4, 2); slBeep(Asharp3, 2); slBeep(C4, 2);
		slBeep(D4, 2); slBeep(G4, 4); slBeep(G4, 8); slBeep(G4, 8); slBeep(G4, 2); slBeep(G3, 2); slBeep(G3, 2); slBeep(Asharp3, 2); slBeep(C4, 2); slBeep(D4, 2);
		slBeep(Dsharp4, 1); slBeep(C4, 1.33f); slBeep(D4, 4); slBeep(Dsharp4, 1); slBeep(C4, 1.33f); slBeep(D4, 4);
		slBeep(Dsharp4, 1); slBeep(C4, 2); slBeep(Dsharp4, 2); slBeep(Gsharp4, 2); slBeep(Gsharp4, 4); slBeep(Gsharp4, 8); slBeep(Gsharp4, 8); slBeep(Gsharp4, 2); slBeep(Gsharp4, 2);
		slBeep(Gsharp4, 0.5f); slBeep(G4, 2); slBeep(F4, 2); slBeep(Dsharp4, 2); slBeep(F4, 2);
		slBeep(G4, 0.66f); slBeep(Dsharp4, 2); slBeep(Dsharp4, 2); slBeep(Asharp3, 4); slBeep(Asharp3, 4); slBeep(Asharp3, 2); slBeep(Asharp3, 2);
		slBeep(F4, 1); slBeep(C4, 1); slBeep(Dsharp4, 2); slBeep(D4, 2); slBeep(C4, 2); slBeep(D4, 2);
		slBeep(Dsharp4, 0.66f); slBeep(C4, 2); slBeep(C4, 2); slBeep(G3, 2); slBeep(Asharp2, 2); slBeep(G3, 2);
		slBeep(Dsharp4, 1); slBeep(D4, 1.33f); slBeep(C4, 4); slBeep(Asharp3, 1); slBeep(Dsharp3, 2); slBeep(Dsharp3, 2);
		slBeep(Asharp3, 0.5f); slBeep(C4); slBeep(D4);
		slBeep(Dsharp4, 0.25f);

		mspb = previousmspb;
		return 0;
	}
	// only contains verse one. accepts int* mspb
	static DWORD WINAPI musicStarSpangledBanner(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; if (lpParam != 0) mspb = *(int*)lpParam;

		std::cout << "O"; slBeep(F, 2); std::cout << "h,"; slBeep(D, 2);
		std::cout << " say,"; slBeep(Asharp2); std::cout << " can" ; slBeep(D); std::cout << " you" ; slBeep(F);
		std::cout << " see," ; slBeep(Asharp, 0.5f); std::cout << " by" ; slBeep(D4, 2); std::cout << " the" ; slBeep(C4, 2);
		std::cout << " dawn's" ; slBeep(Asharp); std::cout << " ear"; slBeep(D); std::cout << "ly" ; slBeep(E);
		std::cout << " light,"; slBeep(F, 0.5f); std::cout << " \nWhat" ; slBeep(F, 2); std::cout << " so" ; slBeep(F, 2);
		std::cout << " proud"; slBeep(D4); std::cout << "ly" ; slBeep(C4); std::cout << " we" ; slBeep(Asharp);
		std::cout << " hailed" ; slBeep(A, 0.5f); std::cout << " at" ; slBeep(G, 2); std::cout << " the" ; slBeep(A, 2);
		std::cout << " twi"; slBeep(Asharp); std::cout << "light's" ; slBeep(Asharp); std::cout << " last" ; slBeep(F);
		std::cout << " gleam"; slBeep(D); std::cout << "ing?"; slBeep(Asharp2); std::cout << "\nWhose" ; slBeep(F, 2); std::cout << " broad" ; slBeep(D, 2);
		std::cout << " stripes" ; slBeep(Asharp2); std::cout << " and" ; slBeep(D); std::cout << " bright" ; slBeep(F);
		std::cout << " stars," ; slBeep(Asharp, 0.5f); std::cout << " through"; slBeep(D4, 2); std::cout << " the"; slBeep(C4, 2);
		std::cout << " per"; slBeep(Asharp); std::cout << "il"; slBeep(D); std::cout << "ous"; slBeep(E);
		std::cout << " fight,"; slBeep(F, 0.5f); std::cout << "\nO'er"; slBeep(F, 2); std::cout << " the"; slBeep(F, 2);
		std::cout << " ram"; slBeep(D4); std::cout << "parts"; slBeep(C4); std::cout << " we"; slBeep(Asharp);
		std::cout << " watched"; slBeep(A, 0.5f); std::cout << " were"; slBeep(G, 2); std::cout << " so"; slBeep(A, 2);
		std::cout << " gal"; slBeep(Asharp); std::cout << "ant"; slBeep(Asharp); std::cout << "ly"; slBeep(F);
		std::cout << " stream"; slBeep(D); std::cout << "ing?"; slBeep(Asharp2); std::cout << "\nAnd"; slBeep(D4, 2); std::cout << " the"; slBeep(D4, 2);
		std::cout << " rock"; slBeep(D4); std::cout << "et's"; slBeep(Dsharp4); std::cout << " red"; slBeep(F4);
		std::cout << " glare,"; slBeep(F4, 0.5f); std::cout << " the"; slBeep(Dsharp4, 2); std::cout << " bombs"; slBeep(D4, 2);
		std::cout << " burst"; slBeep(C4); std::cout << "ing"; slBeep(D4); std::cout << " in"; slBeep(Dsharp4);
		std::cout << " air,"; slBeep(Dsharp4, 0.5f); std::cout << "\nGave"; slBeep(Dsharp4);
		std::cout << " proof"; slBeep(D4); std::cout << " through"; slBeep(C4); std::cout << " the"; slBeep(Asharp);
		std::cout << " night"; slBeep(A, 0.5f); std::cout << " that"; slBeep(G, 2); std::cout << " our"; slBeep(A, 2);
		std::cout << " flag"; slBeep(Asharp); std::cout << " was"; slBeep(D); std::cout << " still"; slBeep(E);
		std::cout << " there."; slBeep(F, 0.5f); std::cout << "\nOh,"; slBeep(F);
		std::cout << " say,"; slBeep(Asharp); std::cout << " does"; slBeep(Asharp); std::cout << " tha"; slBeep(Asharp, 2); std::cout << "t"; slBeep(A, 2);
		std::cout << " star"; slBeep(G); std::cout << " span"; slBeep(G); std::cout << "gled"; slBeep(G);
		std::cout << " ban"; slBeep(C4); std::cout << "ne"; slBeep(Dsharp4, 2); std::cout << "r"; slBeep(D4, 2); std::cout << " ye"; slBeep(C4, 2); std::cout << "t"; slBeep(Asharp, 2);
		std::cout << " wa"; slBeep(Asharp); std::cout << "ve"; slBeep(A); std::cout << "\nO'er"; slBeep(F, 2); std::cout << " the"; slBeep(F, 2);
		std::cout << " la"; slBeep(Asharp, 0.66f); std::cout << "nd"; slBeep(C4, 2); std::cout << " of"; slBeep(D4, 2); std::cout << " the"; slBeep(Dsharp4, 2);
		std::cout << " free"; slBeep(F4, 0.5f); std::cout << " and"; slBeep(Asharp, 2); std::cout << " the"; slBeep(C4, 2);
		std::cout << " home"; slBeep(D4, 0.66f); std::cout << " of"; slBeep(Dsharp4, 2); std::cout << " the"; slBeep(C4);
		std::cout << " brave?"; slBeep(Asharp, 0.5f);

		mspb = previousmspb;
		return 0;
	}
	// accepts int* mspb
	static DWORD WINAPI musicGSTQ(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; if (lpParam != 0) mspb = *(int*)lpParam;

		std::cout << "God"; slBeep(G); std::cout << " save"; slBeep(G); std::cout << " our"; slBeep(A);
		std::cout << " gra"; slBeep(Fsharp, 0.66f); std::cout << "cious"; slBeep(G, 2); std::cout << " Queen,\n"; slBeep(A);
		std::cout << "long"; slBeep(B); std::cout << " live"; slBeep(B); std::cout << " our"; slBeep(C4);
		std::cout << " no"; slBeep(B, 0.66f); std::cout << "ble"; slBeep(A, 2); std::cout << " Queen,\n"; slBeep(G);
		std::cout << "God"; slBeep(A); std::cout << " save"; slBeep(G); std::cout << " the"; slBeep(Fsharp);
		std::cout << " Queen.\n\n"; slBeep(G, 0.33f);

		std::cout << "Send"; slBeep(D4); std::cout << " her"; slBeep(D4); std::cout << " vic"; slBeep(D4);
		std::cout << "to"; slBeep(D4, 0.66f); std::cout << "ri"; slBeep(C4, 2); std::cout << "ous,\n"; slBeep(B);
		std::cout << "hap"; slBeep(C4); std::cout << "py"; slBeep(C4); std::cout << " and"; slBeep(C4);
		std::cout << " glo"; slBeep(C4, 0.66f); std::cout << "ri"; slBeep(B, 2); std::cout << "ous,\n"; slBeep(A);
		std::cout << "long"; slBeep(B); std::cout << " t"; slBeep(C4, 2); std::cout << "o"; slBeep(B, 2); std::cout << " rei"; slBeep(A, 2); std::cout << "gn"; slBeep(G, 2);
		std::cout << " o"; slBeep(B, 0.66f); std::cout << "ver"; slBeep(C4, 2); std::cout << " us;\n"; slBeep(D4);
		std::cout << "Go"; slBeep(E4, 2); std::cout << "d"; slBeep(C4, 2); std::cout << " save"; slBeep(B); std::cout << " the"; slBeep(A);
		std::cout << " Queen.\n\n"; slBeep(G, 0.33f);

		std::cout << "Thy"; slBeep(G); std::cout << " choic"; slBeep(G); std::cout << "est"; slBeep(A);
		std::cout << " gifts"; slBeep(Fsharp, 0.66f); std::cout << " in"; slBeep(G, 2); std::cout << " store\n"; slBeep(A);
		std::cout << "On"; slBeep(B); std::cout << " her"; slBeep(B); std::cout << " be"; slBeep(C4);
		std::cout << " pleased"; slBeep(B, 0.66f); std::cout << " to"; slBeep(A, 2); std::cout << " pour,\n"; slBeep(G);
		std::cout << "Long"; slBeep(A); std::cout << " may"; slBeep(G); std::cout << " she"; slBeep(Fsharp);
		std::cout << " reign.\n\n"; slBeep(G, 0.33f);

		std::cout << "May"; slBeep(D4); std::cout << " she"; slBeep(D4); std::cout << " de"; slBeep(D4);
		std::cout << "fend"; slBeep(D4, 0.66f); std::cout << " our"; slBeep(C4, 2); std::cout << " laws,\n"; slBeep(B);
		std::cout << "And"; slBeep(C4); std::cout << " ev"; slBeep(C4); std::cout << "er"; slBeep(C4);
		std::cout << " give"; slBeep(C4, 0.66f); std::cout << " us"; slBeep(B, 2); std::cout << " cause\n"; slBeep(A);
		std::cout << "To"; slBeep(B); std::cout << " si"; slBeep(C4, 2); std::cout << "ng"; slBeep(B, 2); std::cout << " wi"; slBeep(A, 2); std::cout << "th"; slBeep(G, 2);
		std::cout << " heart"; slBeep(B, 0.66f); std::cout << " and"; slBeep(C4, 2); std::cout << " voice;\n"; slBeep(D4);
		std::cout << "Go"; slBeep(E4, 2); std::cout << "d"; slBeep(C4, 2); std::cout << " save"; slBeep(B); std::cout << " the"; slBeep(A);
		std::cout << " Queen.\n"; slBeep(G, 0.33f);

		mspb = previousmspb;
		return 0;
	}
	// accepts int* mspb
	static DWORD WINAPI musicGSTK(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; if (lpParam != 0) mspb = *(int*)lpParam;

		std::cout << "God"; slBeep(G); std::cout << " save"; slBeep(G); std::cout << " our"; slBeep(A);
		std::cout << " gra"; slBeep(Fsharp, 0.66f); std::cout << "cious"; slBeep(G, 2); std::cout << " King,\n"; slBeep(A);
		std::cout << "long"; slBeep(B); std::cout << " live"; slBeep(B); std::cout << " our"; slBeep(C4);
		std::cout << " no"; slBeep(B, 0.66f); std::cout << "ble"; slBeep(A, 2); std::cout << " King,\n"; slBeep(G);
		std::cout << "God"; slBeep(A); std::cout << " save"; slBeep(G); std::cout << " the"; slBeep(Fsharp);
		std::cout << " King.\n\n"; slBeep(G, 0.33f);

		std::cout << "Send"; slBeep(D4); std::cout << " him"; slBeep(D4); std::cout << " vic"; slBeep(D4);
		std::cout << "to"; slBeep(D4, 0.66f); std::cout << "ri"; slBeep(C4, 2); std::cout << "ous,\n"; slBeep(B);
		std::cout << "hap"; slBeep(C4); std::cout << "py"; slBeep(C4); std::cout << " and"; slBeep(C4);
		std::cout << " glo"; slBeep(C4, 0.66f); std::cout << "ri"; slBeep(B, 2); std::cout << "ous,\n"; slBeep(A);
		std::cout << "long"; slBeep(B); std::cout << " t"; slBeep(C4, 2); std::cout << "o"; slBeep(B, 2); std::cout << " rei"; slBeep(A, 2); std::cout << "gn"; slBeep(G, 2);
		std::cout << " o"; slBeep(B, 0.66f); std::cout << "ver"; slBeep(C4, 2); std::cout << " us;\n"; slBeep(D4);
		std::cout << "Go"; slBeep(E4, 2); std::cout << "d"; slBeep(C4, 2); std::cout << " save"; slBeep(B); std::cout << " the"; slBeep(A);
		std::cout << " King.\n\n"; slBeep(G, 0.33f);

		std::cout << "Thy"; slBeep(G); std::cout << " choic"; slBeep(G); std::cout << "est"; slBeep(A);
		std::cout << " gifts"; slBeep(Fsharp, 0.66f); std::cout << " in"; slBeep(G, 2); std::cout << " store\n"; slBeep(A);
		std::cout << "On"; slBeep(B); std::cout << " him"; slBeep(B); std::cout << " be"; slBeep(C4);
		std::cout << " pleased"; slBeep(B, 0.66f); std::cout << " to"; slBeep(A, 2); std::cout << " pour,\n"; slBeep(G);
		std::cout << "Long"; slBeep(A); std::cout << " may"; slBeep(G); std::cout << " he"; slBeep(Fsharp);
		std::cout << " reign.\n\n"; slBeep(G, 0.33f);

		std::cout << "May"; slBeep(D4); std::cout << " he"; slBeep(D4); std::cout << " de"; slBeep(D4);
		std::cout << "fend"; slBeep(D4, 0.66f); std::cout << " our"; slBeep(C4, 2); std::cout << " laws,\n"; slBeep(B);
		std::cout << "And"; slBeep(C4); std::cout << " ev"; slBeep(C4); std::cout << "er"; slBeep(C4);
		std::cout << " give"; slBeep(C4, 0.66f); std::cout << " us"; slBeep(B, 2); std::cout << " cause\n"; slBeep(A);
		std::cout << "To"; slBeep(B); std::cout << " si"; slBeep(C4, 2); std::cout << "ng"; slBeep(B, 2); std::cout << " wi"; slBeep(A, 2); std::cout << "th"; slBeep(G, 2);
		std::cout << " heart"; slBeep(B, 0.66f); std::cout << " and"; slBeep(C4, 2); std::cout << " voice;\n"; slBeep(D4);
		std::cout << "Go"; slBeep(E4, 2); std::cout << "d"; slBeep(C4, 2); std::cout << " save"; slBeep(B); std::cout << " the"; slBeep(A);
		std::cout << " King.\n"; slBeep(G, 0.33f);

		mspb = previousmspb;
		return 0;
	}

	static DWORD WINAPI musicAllStar(LPVOID lpParam = 0)
        {
            float previousmspb = mspb; mspb = 550;
            std::cout << "Some";
            slBeep(Fsharp);
            std::cout << "bo";
            slBeep(Csharp4, 2);
            std::cout << "dy ";
            slBeep(Asharp, 2);
            std::cout << "once ";
            slBeep(Asharp);
            std::cout << "told ";
            slBeep(Gsharp, 2);
            std::cout << "me ";
            slBeep(Fsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp, 2);
            std::cout << "world ";
            slBeep(B);
            std::cout << "is ";
            slBeep(Asharp, 2);
            std::cout << "gon";
            slBeep(Asharp, 2);
            std::cout << "na ";
            slBeep(Gsharp, 2);
            std::cout << "roll ";
            slBeep(Gsharp, 2);
            std::cout << "me,\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);

            std::cout << "I ";
            slBeep(Fsharp, 2);
            std::cout << "ain't ";
            slBeep(Csharp4, 2);
            std::cout << "the ";
            slBeep(Asharp, 2);
            std::cout << "sharp";
            slBeep(Asharp, 2);
            std::cout << "est ";
            slBeep(Gsharp, 2);
            std::cout << "tool ";
            slBeep(Gsharp, 2);
            std::cout << "in ";
            slBeep(Fsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp, 2);
            std::cout << "sh";
            slBeep(Dsharp);
            std::cout << "ed\n";
            slBeep(Csharp, 0.666f);
            slBeep();

            std::cout << "She ";
            slBeep(Fsharp, 2);
            std::cout << "was ";
            slBeep(Fsharp, 2);
            std::cout << "look";
            slBeep(Csharp4, 2);
            std::cout << "ing ";
            slBeep(Asharp, 2);
            std::cout << "kind ";
            slBeep(Asharp, 2);
            std::cout << "of ";
            slBeep(Gsharp, 2);
            std::cout << "dumb \n";
            slBeep(Gsharp, 2);
            std::cout << "with ";
            slBeep(Fsharp, 2);
            std::cout << "her ";
            slBeep(Fsharp, 2);
            std::cout << "fin";
            slBeep(B);
            std::cout << "ger ";
            slBeep(Asharp, 2);
            std::cout << "and ";
            slBeep(Asharp, 2);
            std::cout << "her ";
            slBeep(Gsharp, 2);
            std::cout << "thumb ";
            slBeep(Gsharp, 2);
            std::cout << "in ";
            slBeep(Fsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp, 2);
            std::cout << "shape ";
            slBeep(Csharp4);
            std::cout << "of ";
            slBeep(Asharp, 2);
            std::cout << "an ";
            slBeep(Asharp, 2);
            std::cout << "L ";
            slBeep(Gsharp);
            std::cout << "on ";
            slBeep(Fsharp, 2);
            std::cout << "her ";
            slBeep(Fsharp, 2);
            std::cout << "fore";
            slBeep(Gsharp);
            std::cout << "head\n";
            slBeep(Dsharp, 0.666f);
            slBeep();

            std::cout << "Well, ";
            slBeep(Fsharp, 1.333f);
            std::cout << "the ";
            slBeep(Fsharp, 4);
            std::cout << "years ";
            slBeep(Fsharp, 2);
            std::cout << "start ";
            slBeep(Fsharp, 2);
            std::cout << "com";
            slBeep(Fsharp, 4);
            std::cout << "ing ";
            slBeep(Fsharp, 4);
            std::cout << "and ";
            slBeep(Fsharp, 4);
            std::cout << "they ";
            slBeep(Fsharp, 4);
            std::cout << "don't ";
            slBeep(Fsharp, 2);
            std::cout << "stop ";
            slBeep(Fsharp, 2);
            std::cout << "com";
            slBeep(Fsharp, 4);
            std::cout << "ing,\n";
            slBeep(Fsharp, 1.333f);

            std::cout << "Fed ";
            slBeep(Fsharp, 2);
            std::cout << "to ";
            slBeep(Fsharp, 4);
            std::cout << "the ";
            slBeep(Fsharp, 4);
            std::cout << "rules ";
            slBeep(Fsharp, 2);
            std::cout << "and ";
            slBeep(Fsharp, 4);
            std::cout << "I ";
            slBeep(Fsharp, 4);
            std::cout << "hit ";
            slBeep(Fsharp, 4);
            std::cout << "the ";
            slBeep(Fsharp, 4);
            std::cout << "ground ";
            slBeep(Fsharp, 2);
            std::cout << "run";
            slBeep(Asharp, 4);
            std::cout << "ning,\n";
            slBeep(Fsharp, 1.333f);

            std::cout << "Did";
            slBeep(Asharp, 4);
            std::cout << "n't ";
            slBeep(Csharp4, 4);
            std::cout << "make ";
            slBeep(Csharp4, 2);
            std::cout << "sense ";
            slBeep(Csharp4, 2);
            std::cout << "not ";
            slBeep(B, 4);
            std::cout << "to ";
            slBeep(B, 4);
            std::cout << "live ";
            slBeep(Asharp, 2);
            std::cout << "for ";
            slBeep(Asharp, 2);
            std::cout << "fun\n";
            slBeep(Asharp, 1.333f);

            std::cout << "Your ";
            slBeep(Csharp, 4);
            std::cout << "brain ";
            slBeep(Asharp, 2);
            std::cout << "gets ";
            slBeep(Fsharp, 2);
            std::cout << "smart ";
            slBeep(Fsharp, 2);
            std::cout << "but ";
            slBeep(Fsharp, 4);
            std::cout << "your ";
            slBeep(Dsharp, 4);
            std::cout << "head ";
            slBeep(Fsharp, 2);
            std::cout << "gets ";
            slBeep(Fsharp, 2);
            std::cout << "du";
            slBeep(Dsharp, 4);
            std::cout << "mb\n";
            slBeep(Csharp, 1.333f);

            //Bar 14
            std::cout << "So ";
            slBeep(Asharp, 4);
            std::cout << "much ";
            slBeep(Csharp4, 2);
            std::cout << "to ";
            slBeep(Asharp, 4);
            std::cout << "do, ";
            slBeep(Dsharp4, 2);
            std::cout << "so ";
            slBeep(Asharp, 4);
            std::cout << "much ";
            slBeep(Csharp4, 2);
            std::cout << "to ";
            slBeep(Asharp, 4);
            std::cout << "see, \n";
            slBeep(Dsharp4, 2);
            std::cout << "so ";
            slBeep(Asharp, 4);
            std::cout << "what's ";
            slBeep(Csharp4, 2);
            std::cout << "wrong ";
            slBeep(B, 2);
            std::cout << "with ";
            slBeep(Asharp, 2);
            std::cout << "tak";
            slBeep(Gsharp, 2);
            std::cout << "ing ";
            slBeep(Gsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp, 4);
            std::cout << "back ";
            slBeep(Gsharp, 2);
            std::cout << "streets?\n";
            slBeep(Fsharp, 2);
            slBeep(R, 1.333f);

            std::cout << "You'll ";
            slBeep(Csharp, 4);
            std::cout << "ne";
            slBeep(Fsharp, 4);
            std::cout << "ver ";
            slBeep(Fsharp, 4);
            std::cout << "know ";
            slBeep(Fsharp, 2);
            std::cout << "if ";
            slBeep(Fsharp, 4);
            std::cout << "you ";
            slBeep(Fsharp, 4);
            std::cout << "don't ";
            slBeep(Fsharp, 2);
            std::cout << "go\n";
            slBeep(Fsharp);
            slBeep(R, 1.333f);

            std::cout << "You'll ";
            slBeep(Csharp, 4);
            std::cout << "ne";
            slBeep(Asharp, 4);
            std::cout << "ver ";
            slBeep(Fsharp, 4);
            std::cout << "shine ";
            slBeep(Fsharp, 2);
            std::cout << "if ";
            slBeep(Fsharp, 4);
            std::cout << "you ";
            slBeep(Dsharp, 4);
            std::cout << "don't ";
            slBeep(Dsharp, 2);
            std::cout << "glow\n";
            slBeep(Dsharp);
            slBeep();

            //Bar 18
            std::cout << "Hey ";
            slBeep(Asharp, 2);
            std::cout << "now\n";
            slBeep(Fsharp);
            std::cout << "You're ";
            slBeep(Fsharp, 4);
            std::cout << "an ";
            slBeep(Dsharp, 4);
            std::cout << "All ";
            slBeep(Fsharp, 2);
            std::cout << "Star\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 4);
            std::cout << "your ";
            slBeep(Dsharp, 4);
            std::cout << "game ";
            slBeep(Fsharp, 2);
            std::cout << "on\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Go ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "play\n";
            slBeep(Asharp, 0.8f);

            //Bar 20
            std::cout << "Hey ";
            slBeep(Asharp, 2);
            std::cout << "now\n";
            slBeep(Fsharp);
            std::cout << "You're ";
            slBeep(Fsharp, 4);
            std::cout << "a ";
            slBeep(Dsharp, 4);
            std::cout << "rock ";
            slBeep(Fsharp, 2);
            std::cout << "star\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 4);
            std::cout << "the ";
            slBeep(Dsharp, 4);
            std::cout << "show ";
            slBeep(Fsharp, 2);
            std::cout << "on\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "paid\n";
            slBeep(Asharp, 0.8f);

            //Bar 22
            std::cout << "All ";
            slBeep(Asharp);
            std::cout << "that ";
            slBeep(Csharp4);
            std::cout << "glit";
            slBeep(B, 2);
            std::cout << "ters ";
            slBeep(Asharp, 2);
            std::cout << "is ";
            slBeep(Gsharp, 2);
            std::cout << "go";
            slBeep(Gsharp, 2);
            std::cout << "ld\n";
            slBeep(Fsharp, 0.5f);

            std::cout << "Onl";
            slBeep(Fsharp, 2);
            std::cout << "y ";
            slBeep(Fsharp, 2);
            std::cout << "shoot";
            slBeep(Gsharp, 2);
            std::cout << "ing ";
            slBeep(Fsharp, 2);
            std::cout << "sta";
            slBeep(Asharp, 2);
            std::cout << "rs ";
            slBeep(Gsharp, 0.8f);
            std::cout << "break ";
            slBeep(Gsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp);
            std::cout << "mo";
            slBeep(Gsharp, 2);
            std::cout << "l";
            slBeep(Asharp, 2);
            std::cout << "d\n";
            slBeep(Dsharp, 0.333f);
            //
            //End chorus
            //

            std::cout << "It's ";
            slBeep(Fsharp, 4);
            std::cout << "a ";
            slBeep(Fsharp, 4);
            std::cout << "cool ";
            slBeep(Fsharp, 2);
            std::cout << "place, ";
            slBeep(Fsharp, 2); slBeep(R, 2);
            std::cout << "and ";
            slBeep(Fsharp, 4);
            std::cout << "they ";
            slBeep(Fsharp, 4);
            std::cout << "say ";
            slBeep(Fsharp, 4);
            std::cout << "it ";
            slBeep(Fsharp, 4);
            std::cout << "gets ";
            slBeep(Fsharp, 2);
            std::cout << "cold";
            slBeep(Fsharp, 4);
            std::cout << "er\n";
            slBeep(Fsharp, 2);

            std::cout << "You're ";
            slBeep(Csharp, 4);
            std::cout << "bund";
            slBeep(Fsharp, 4);
            std::cout << "led ";
            slBeep(Fsharp, 4);
            std::cout << "up ";
            slBeep(Fsharp, 2);
            std::cout << "now, ";
            slBeep(Fsharp, 2);
            std::cout << "wait ";
            slBeep(Fsharp, 2);
            std::cout << "'til ";
            slBeep(Fsharp, 4);
            std::cout << "you ";
            slBeep(Fsharp, 4);
            std::cout << "get ";
            slBeep(Fsharp, 2);
            std::cout << "old";
            slBeep(Asharp, 4);
            std::cout << "er\n";
            slBeep(Fsharp, 4);

            std::cout << "But ";
            slBeep(Csharp, 4);
            std::cout << "the ";
            slBeep(Csharp, 4);
            std::cout << "me";
            slBeep(Asharp, 4);
            std::cout << "te";
            slBeep(Csharp4, 4);
            std::cout << "or ";
            slBeep(Csharp4, 4);
            std::cout << "men ";
            slBeep(B, 2);
            std::cout << "beg ";
            slBeep(Asharp, 2);
            std::cout << "to ";
            slBeep(Gsharp, 4);
            std::cout << "diff";
            slBeep(Gsharp, 4);
            std::cout << "er\n";
            slBeep(Fsharp, 1.333f);
            std::cout << "Judg";
            slBeep(Fsharp, 4);
            std::cout << "ing ";
            slBeep(Fsharp, 4);
            std::cout << "by ";
            slBeep(Fsharp, 4);
            std::cout << "the ";
            slBeep(Gsharp, 4);
            std::cout << "hole ";
            slBeep(Asharp, 2);
            std::cout << "in ";
            slBeep(Gsharp, 4);
            std::cout << "the ";
            slBeep(Fsharp, 4);
            std::cout << "sat";
            slBeep(Gsharp, 4);
            std::cout << "el";
            slBeep(Fsharp, 4);
            std::cout << "ite ";
            slBeep(Dsharp, 2);
            std::cout << "pic";
            slBeep(Dsharp, 4);
            std::cout << "ture\n";
            slBeep(Dsharp, 2);

            std::cout << "The ";
            slBeep(Csharp, 4);
            std::cout << "ice ";
            slBeep(Asharp, 2);
            std::cout << "we ";
            slBeep(Csharp4, 2);
            std::cout << "skate ";
            slBeep(Dsharp4, 1.333f);
            std::cout << "is ";
            slBeep(Csharp, 4);
            std::cout << "get";
            slBeep(Asharp, 4);
            std::cout << "ting ";
            slBeep(Fsharp, 4);
            std::cout << "pret";
            slBeep(Fsharp, 4);
            std::cout << "ty ";
            slBeep(Fsharp, 4);
            std::cout << "thin\n";
            slBeep(Fsharp, 1.333f);

            std::cout << "The ";
            slBeep(Csharp, 4);
            std::cout << "wa";
            slBeep(Fsharp, 4);
            std::cout << "ter's ";
            slBeep(Gsharp, 4);
            std::cout << "get";
            slBeep(Asharp, 4);
            std::cout << "ting ";
            slBeep(Csharp4, 4);
            std::cout << "warm ";
            slBeep(B, 2);
            std::cout << "so ";
            slBeep(Asharp, 4);
            std::cout << "you ";
            slBeep(Gsharp, 4);
            std::cout << "might ";
            slBeep(Asharp, 4);
            std::cout << "as ";
            slBeep(Gsharp, 4);
            std::cout << "well ";
            slBeep(Dsharp, 2);
            std::cout << "swim\n";
            slBeep(Dsharp, 1.333f);

            std::cout << "My ";
            slBeep(Csharp, 4);
            std::cout << "world's ";
            slBeep(Dsharp4, 2);
            std::cout << "on ";
            slBeep(Csharp4, 2);
            std::cout << "fi";
            slBeep(Csharp4, 4);
            std::cout << "re, ";
            slBeep(Csharp4, 1.333f);
            std::cout << "how ";
            slBeep(Asharp, 4);
            std::cout << "'bout ";
            slBeep(Fsharp, 2);
            std::cout << "yours? \n";
            slBeep(Fsharp, 0.8f);

            std::cout << "But ";
            slBeep(Fsharp, 4);
            std::cout << "that's ";
            slBeep(Fsharp, 4);
            std::cout << "the ";
            slBeep(Fsharp, 4);
            std::cout << "way ";
            slBeep(Gsharp, 4);
            std::cout << "I ";
            slBeep(Asharp, 4);
            std::cout << "like ";
            slBeep(Fsharp, 4);
            std::cout << "it ";
            slBeep(Fsharp, 4);
            std::cout << "and ";
            slBeep(Gsharp, 4);
            std::cout << "I'll ";
            slBeep(Asharp, 4);
            std::cout << "never ";
            slBeep(Fsharp, 4);
            std::cout << "get ";
            slBeep(Dsharp, 2);
            std::cout << "bored\n";
            slBeep(Dsharp, 1.333f);
            slBeep();

            //
            //Chorus
            //
            std::cout << "Hey ";
            slBeep(Asharp, 2);
            std::cout << "now\n";
            slBeep(Fsharp);
            std::cout << "You're ";
            slBeep(Fsharp, 4);
            std::cout << "an ";
            slBeep(Dsharp, 4);
            std::cout << "All ";
            slBeep(Fsharp, 2);
            std::cout << "Star\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 4);
            std::cout << "your ";
            slBeep(Dsharp, 4);
            std::cout << "game ";
            slBeep(Fsharp, 2);
            std::cout << "on\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Go ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "play\n";
            slBeep(Asharp, 0.8f);

            std::cout << "Hey ";
            slBeep(Asharp, 2);
            std::cout << "now\n";
            slBeep(Fsharp);
            std::cout << "You're ";
            slBeep(Fsharp, 4);
            std::cout << "a ";
            slBeep(Dsharp, 4);
            std::cout << "rock ";
            slBeep(Fsharp, 2);
            std::cout << "star\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 4);
            std::cout << "the ";
            slBeep(Dsharp, 4);
            std::cout << "show ";
            slBeep(Fsharp, 2);
            std::cout << "on\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "paid\n";
            slBeep(Asharp, 0.8f);

            //Bar 22
            std::cout << "All ";
            slBeep(Asharp);
            std::cout << "that ";
            slBeep(Csharp4);
            std::cout << "glit";
            slBeep(B, 2);
            std::cout << "ters ";
            slBeep(Asharp, 2);
            std::cout << "is ";
            slBeep(Gsharp, 2);
            std::cout << "go";
            slBeep(Gsharp, 2);
            std::cout << "ld\n";
            slBeep(Fsharp, 0.5f);

            std::cout << "Onl";
            slBeep(Fsharp, 2);
            std::cout << "y ";
            slBeep(Fsharp, 2);
            std::cout << "shoot";
            slBeep(Gsharp, 2);
            std::cout << "ing ";
            slBeep(Fsharp, 2);
            std::cout << "sta";
            slBeep(Asharp, 2);
            std::cout << "rs ";
            slBeep(Gsharp, 0.8f);
            std::cout << "break ";
            slBeep(Gsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp);
            std::cout << "mo";
            slBeep(Gsharp, 2);
            std::cout << "l";
            slBeep(Asharp, 2);
            std::cout << "d\n";
            slBeep(Dsharp, 0.333f);
            //
            //End chorus
            //

            //instrumental solo
            std::cout << "*whistling*\n";
            for (byte b0 = 0; b0 < 4; b0++)
            {
                slBeep(Csharp5); slBeep(Asharp4); slBeep(Gsharp4, 2); slBeep(Fsharp4, 2); slBeep(R, 2);
                slBeep(Asharp4); slBeep(B4, 2); slBeep(Asharp4); slBeep(Gsharp4, 2); slBeep(Fsharp4, 2); slBeep(Dsharp4, 2); slBeep(Csharp4, 2);
            }

            //
            //Chorus ed2
            //
            std::cout << "Hey ";
            slBeep(Asharp, 2);
            std::cout << "now\n";
            slBeep(Fsharp);
            std::cout << "You're ";
            slBeep(Fsharp, 4);
            std::cout << "an ";
            slBeep(Dsharp, 4);
            std::cout << "All ";
            slBeep(Fsharp, 2);
            std::cout << "Star\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 4);
            std::cout << "your ";
            slBeep(Dsharp, 4);
            std::cout << "game ";
            slBeep(Fsharp, 2);
            std::cout << "on\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Go ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "play\n";
            slBeep(Asharp, 0.8f);

            std::cout << "Hey ";
            slBeep(Asharp, 2);
            std::cout << "now\n";
            slBeep(Fsharp);
            std::cout << "You're ";
            slBeep(Fsharp, 4);
            std::cout << "a ";
            slBeep(Dsharp, 4);
            std::cout << "rock ";
            slBeep(Fsharp, 2);
            std::cout << "star\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 4);
            std::cout << "the ";
            slBeep(Dsharp, 4);
            std::cout << "show ";
            slBeep(Fsharp, 2);
            std::cout << "on\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "paid\n";
            slBeep(Asharp, 0.8f);

            //Bar 54
            std::cout << "All ";
            slBeep(Asharp);
            std::cout << "that ";
            slBeep(Csharp4);
            std::cout << "glit";
            slBeep(B, 2);
            std::cout << "ters ";
            slBeep(Csharp4, 2);
            std::cout << "is ";
            slBeep(Dsharp4, 2);
            std::cout << "gold\n";
            slBeep(Fsharp4, 0.4f);

            std::cout << "Onl";
            slBeep(Fsharp, 2);
            std::cout << "y ";
            slBeep(Fsharp, 2);
            std::cout << "shoot";
            slBeep(Gsharp, 2);
            std::cout << "ing ";
            slBeep(Fsharp, 2);
            std::cout << "sta";
            slBeep(Asharp, 2);
            std::cout << "rs \n";
            slBeep(Gsharp, 0.666f);
            //
            //End chorus ed2
            //

            slBeep();

            std::cout << "Some";
            slBeep(Fsharp);
            std::cout << "bo";
            slBeep(Csharp4, 2);
            std::cout << "dy ";
            slBeep(Asharp, 2);
            std::cout << "once ";
            slBeep(Asharp);
            std::cout << "asked ";
            slBeep(Gsharp, 2);
            std::cout << "could ";
            slBeep(Fsharp, 2);
            std::cout << "I ";
            slBeep(Fsharp, 2);
            std::cout << "spare ";
            slBeep(B);
            std::cout << "some ";
            slBeep(Asharp, 2);
            std::cout << "change ";
            slBeep(Asharp, 2);
            std::cout << "for ";
            slBeep(Gsharp, 2);
            std::cout << "gas\n";
            slBeep(Gsharp, 2);

            std::cout << "I ";
            slBeep(Fsharp, 2);
            std::cout << "need ";
            slBeep(Gsharp, 2);
            std::cout << "to ";
            slBeep(Fsharp, 2);
            std::cout << "get ";
            slBeep(Csharp4, 2);
            std::cout << "my";
            slBeep(Asharp, 2);
            std::cout << "self ";
            slBeep(Asharp, 2);
            std::cout << "a";
            slBeep(Gsharp, 2);
            std::cout << "way ";
            slBeep(Gsharp, 2);
            std::cout << "from ";
            slBeep(Fsharp, 2);
            std::cout << "this ";
            slBeep(Fsharp, 2);
            std::cout << "pla";
            slBeep(Dsharp);
            std::cout << "ce\n";
            slBeep(Csharp, 0.666f);
            slBeep();

            std::cout << "I ";
            slBeep(Csharp4, 4);
            std::cout << "said ";
            slBeep(Csharp4, 1.333f);
            std::cout << "yep, ";
            slBeep(Csharp4);
            std::cout << "what ";
            slBeep(Asharp, 4);
            std::cout << "a ";
            slBeep(Gsharp, 4);
            std::cout << "con";
            slBeep(Asharp, 2);
            std::cout << "cept\n";
            slBeep(Gsharp);
            std::cout << "I ";
            slBeep(Gsharp, 4);
            std::cout << "could ";
            slBeep(Csharp4, 1.333f);
            std::cout << "use ";
            slBeep(B, 4);
            std::cout << "a ";
            slBeep(Asharp, 4);
            std::cout << "lit";
            slBeep(B, 4);
            std::cout << "tle ";
            slBeep(Asharp, 4);
            std::cout << "fuel ";
            slBeep(B, 2);
            std::cout << "my";
            slBeep(Fsharp, 2);
            std::cout << "self,\n";
            slBeep(Dsharp, 2);
            std::cout << "And ";
            slBeep(Csharp, 2);
            std::cout << "we ";
            slBeep(Dsharp, 2);
            std::cout << "could ";
            slBeep(Csharp, 2);
            std::cout << "all ";
            slBeep(Csharp4);
            std::cout << "use ";
            slBeep(Asharp, 4);
            std::cout << "a ";
            slBeep(Asharp, 4);
            std::cout << "lit";
            slBeep(Gsharp, 2);
            std::cout << "tle ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "cha";
            slBeep(Gsharp);
            std::cout << "nge\n";
            slBeep(Asharp, 0.4f);

            std::cout << "Well, ";
            slBeep(Csharp4, 1.333f);
            std::cout << "the ";
            slBeep(Csharp4, 4);
            std::cout << "years ";
            slBeep(Csharp4, 2);
            std::cout << "start ";
            slBeep(Csharp4, 2);
            std::cout << "com";
            slBeep(Csharp4, 4);
            std::cout << "ing ";
            slBeep(Csharp4, 4);
            std::cout << "and ";
            slBeep(Csharp4, 4);
            std::cout << "they ";
            slBeep(Csharp4, 4);
            std::cout << "don't ";
            slBeep(Csharp4, 2);
            std::cout << "stop ";
            slBeep(Csharp4, 2);
            std::cout << "com";
            slBeep(Csharp4, 4);
            std::cout << "ing,\n";
            slBeep(Csharp4, 1.333f);

            std::cout << "Fed ";
            slBeep(Csharp4, 2);
            std::cout << "to ";
            slBeep(Csharp4, 4);
            std::cout << "the ";
            slBeep(Csharp4, 4);
            std::cout << "rules ";
            slBeep(Csharp4, 2);
            std::cout << "and ";
            slBeep(Csharp4, 4);
            std::cout << "I ";
            slBeep(Csharp4, 4);
            std::cout << "hit ";
            slBeep(Csharp4, 4);
            std::cout << "the ";
            slBeep(Csharp4, 4);
            std::cout << "ground ";
            slBeep(Csharp4, 2);
            std::cout << "run";
            slBeep(Dsharp4, 4);
            std::cout << "ning,\n";
            slBeep(Csharp4, 1.333f);

            std::cout << "Did";
            slBeep(Asharp, 4);
            std::cout << "n't ";
            slBeep(Csharp4, 4);
            std::cout << "make ";
            slBeep(Csharp4, 2);
            std::cout << "sense ";
            slBeep(Csharp4, 2);
            std::cout << "not ";
            slBeep(B, 4);
            std::cout << "to ";
            slBeep(B, 4);
            std::cout << "live ";
            slBeep(Asharp, 2);
            std::cout << "for ";
            slBeep(Asharp, 2);
            std::cout << "fun\n";
            slBeep(Asharp, 1.333f);

            std::cout << "Your ";
            slBeep(Csharp, 4);
            std::cout << "brain ";
            slBeep(Asharp, 2);
            std::cout << "gets ";
            slBeep(Fsharp, 2);
            std::cout << "smart ";
            slBeep(Fsharp, 2);
            std::cout << "but ";
            slBeep(Fsharp, 4);
            std::cout << "your ";
            slBeep(Dsharp, 4);
            std::cout << "head ";
            slBeep(Fsharp, 2);
            std::cout << "gets ";
            slBeep(Fsharp, 2);
            std::cout << "du";
            slBeep(Dsharp, 4);
            std::cout << "mb\n";
            slBeep(Csharp, 1.333f);

            //Bar 69
            std::cout << "So ";
            slBeep(Asharp, 4);
            std::cout << "much ";
            slBeep(Csharp4, 2);
            std::cout << "to ";
            slBeep(Asharp, 4);
            std::cout << "do, ";
            slBeep(Dsharp4, 2);
            std::cout << "so ";
            slBeep(Asharp, 4);
            std::cout << "much ";
            slBeep(Csharp4, 2);
            std::cout << "to ";
            slBeep(Asharp, 4);
            std::cout << "see, \n";
            slBeep(Dsharp4, 2);
            std::cout << "so ";
            slBeep(Asharp, 4);
            std::cout << "what's ";
            slBeep(Csharp4, 2);
            std::cout << "wrong ";
            slBeep(B, 2);
            std::cout << "with ";
            slBeep(Asharp, 2);
            std::cout << "tak";
            slBeep(Gsharp, 2);
            std::cout << "ing ";
            slBeep(Gsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp, 4);
            std::cout << "back ";
            slBeep(Gsharp, 2);
            std::cout << "streets?\n";
            slBeep(Fsharp, 2);
            slBeep(R, 1.333f);

            std::cout << "You'll ";
            slBeep(Csharp, 4);
            std::cout << "ne";
            slBeep(Fsharp, 4);
            std::cout << "ver ";
            slBeep(Fsharp, 4);
            std::cout << "know ";
            slBeep(Fsharp, 2);
            std::cout << "if ";
            slBeep(Fsharp, 4);
            std::cout << "you ";
            slBeep(Fsharp, 4);
            std::cout << "don't ";
            slBeep(Fsharp, 2);
            std::cout << "go\n";
            slBeep(Fsharp);
            slBeep(R, 1.333f);

            std::cout << "You'll ";
            slBeep(Csharp, 4);
            std::cout << "ne";
            slBeep(Dsharp4, 4);
            std::cout << "ver ";
            slBeep(Csharp4, 4);
            std::cout << "shine ";
            slBeep(Csharp4, 2);
            std::cout << "if ";
            slBeep(Csharp4, 4);
            std::cout << "you ";
            slBeep(Csharp4, 4);
            std::cout << "don't ";
            slBeep(Csharp4, 2);
            std::cout << "glow\n";
            slBeep(Csharp4);
            slBeep();

            //Bar 73
            //
            //Chorus ed3
            //
            std::cout << "Hey ";
            slBeep(Asharp, 2);
            std::cout << "now\n";
            slBeep(Fsharp);
            std::cout << "You're ";
            slBeep(Fsharp, 4);
            std::cout << "an ";
            slBeep(Dsharp, 4);
            std::cout << "All ";
            slBeep(Fsharp, 2);
            std::cout << "Star\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 4);
            std::cout << "your ";
            slBeep(Dsharp, 4);
            std::cout << "game ";
            slBeep(Fsharp, 2);
            std::cout << "on\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Go ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "play\n";
            slBeep(Asharp, 0.8f);

            std::cout << "Hey ";
            slBeep(Asharp, 2);
            std::cout << "now\n";
            slBeep(Fsharp);
            std::cout << "You're ";
            slBeep(Fsharp, 4);
            std::cout << "a ";
            slBeep(Dsharp, 4);
            std::cout << "rock ";
            slBeep(Fsharp, 2);
            std::cout << "star\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 4);
            std::cout << "the ";
            slBeep(Dsharp, 4);
            std::cout << "show ";
            slBeep(Fsharp, 2);
            std::cout << "on\n";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "Get ";
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            std::cout << "paid\n";
            slBeep(Asharp);

            slBeep(Csharp, 2);
            //Bar 54
            std::cout << "All ";
            slBeep(Asharp);
            std::cout << "that ";
            slBeep(Csharp4);
            std::cout << "glit";
            slBeep(B, 2);
            std::cout << "ters ";
            slBeep(Csharp4, 2);
            std::cout << "is ";
            slBeep(Dsharp4, 2);
            std::cout << "g";
            slBeep(Fsharp4, 2);

            std::cout << "o";
            slBeep(Gsharp4, 2);
            std::cout << "ld\n";
            slBeep(Fsharp4, 0.666f);

            std::cout << "Onl";
            slBeep(Fsharp, 2);
            std::cout << "y ";
            slBeep(Fsharp, 2);
            std::cout << "shoot";
            slBeep(Gsharp, 2);
            std::cout << "ing ";
            slBeep(Fsharp, 2);

            std::cout << "sta";
            slBeep(Csharp4, 2);
            std::cout << "rs ";
            slBeep(Asharp, 0.666f);
            std::cout << "break ";
            slBeep(Gsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp);
            std::cout << "mo";
            slBeep(Gsharp, 2);
            std::cout << "l";
            slBeep(Asharp, 2);
            std::cout << "d\n";
            slBeep(Fsharp, 0.333f);

            slBeep(Csharp, 2);
            //Bar 81
            std::cout << "All ";
            slBeep(Asharp);
            std::cout << "that ";
            slBeep(Csharp4);
            std::cout << "glit";
            slBeep(B, 2);
            std::cout << "ters ";
            slBeep(Csharp4, 2);
            std::cout << "is ";
            slBeep(Dsharp4, 2);
            std::cout << "g";
            slBeep(Fsharp4, 2);

            std::cout << "o";
            slBeep(Gsharp4, 2);
            std::cout << "ld\n";
            slBeep(Fsharp4, 0.666f);

            std::cout << "Onl";
            slBeep(Fsharp, 2);
            std::cout << "y ";
            slBeep(Fsharp, 2);
            std::cout << "shoot";
            slBeep(Gsharp, 2);
            std::cout << "ing ";
            slBeep(Fsharp, 2);

            std::cout << "sta";
            slBeep(Csharp4, 2);
            std::cout << "rs ";
            slBeep(Asharp, 0.666f);
            std::cout << "break ";
            slBeep(Gsharp, 2);
            std::cout << "the ";
            slBeep(Fsharp);
            std::cout << "mo";
            slBeep(Gsharp, 2);
            std::cout << "l";
            slBeep(Asharp, 2);
            std::cout << "d\n";
            slBeep(Dsharp, 0.286f); // seven halfs

            mspb = previousmspb;
			return 0;
        }

	static DWORD WINAPI musicDarkKnight(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; mspb = 400;

		printCIA();
		std::cout << "Doc";		slBeep(F3, 2);
		std::cout << "tor ";	slBeep(D3, 2);
		std::cout << "Pa";		slBeep(G3);
		std::cout << "val";		slBeep(D3, 2);
		std::cout << ", ";		slBeep(R, 0.5f);
		std::cout << "I'm ";	slBeep(F3, 2);
		std::cout << "C";		slBeep(Gsharp3, 2);
		std::cout << "I";		slBeep(Asharp3, 2);
		std::cout << "A.";		slBeep(G3);
		slBeep(R, 0.25f);

		std::cout << "\n";
		printDriver();
		std::cout << "He ";		slBeep(Dsharp3, 2);
		std::cout << "was";		slBeep(Dsharp3, 2);
		std::cout << "n't ";	slBeep(D3, 2);
		std::cout << "a";		slBeep(D3, 2);
		std::cout << "lone.";	slBeep(C3);
		slBeep(R, 0.25f);

		std::cout << "\n";
		printCIA();
		std::cout << "You ";	slBeep(F3, 2);
		std::cout << "don't ";	slBeep(Gsharp3);
		std::cout << "get ";	slBeep(E3, 2);
		std::cout << "to ";		slBeep(D3, 4);
		std::cout << "bring ";	slBeep(Gsharp3);
		std::cout << "friends.";slBeep(G3);
		slBeep(R, 0.25f);

		std::cout << "\n";
		printPavel();
		std::cout << "They ";	slBeep(D2, 2);
		std::cout << "are ";	slBeep(E2, 2);
		std::cout << "not ";	slBeep(F2, 2);
		std::cout << "my ";		slBeep(E2, 2);
		std::cout << "friends.";slBeep(Dsharp2);
		slBeep(R, 0.25f);
		
		std::cout << "\n";
		printDriver();
		std::cout << "Don't ";	slBeep(Fsharp3, 2);
		std::cout << "wo";		slBeep(F3, 2);
		std::cout << "rry";		slBeep(G3, 2);
		std::cout << ", ";		slBeep();
		std::cout << "no ";		slBeep(F3, 2);
		std::cout << "charge ";	slBeep(Gsharp3, 1.5f);
		std::cout << "for ";	slBeep(F3, 2);
		std::cout << "them";	slBeep(G3, 1.5f);
		slBeep(R, 0.25f);

		std::cout << "\n";
		printCIA();
		std::cout << "And ";	slBeep(C3, 2);
		std::cout << "why ";	slBeep(Gsharp3);
		std::cout << "would ";	slBeep(F3, 2);
		std::cout << "I ";		slBeep(F3, 3);
		std::cout << "want ";	slBeep(D3);
		std::cout << "them?";	slBeep(Gsharp3);
		slBeep(R, 0.25f);

		std::cout << "\n";
		printDriver();
		std::cout << "They ";	slBeep(Fsharp3, 2);
		std::cout << "were ";	slBeep(F3, 2);
		std::cout << "try";		slBeep(G3, 3);
		std::cout << "ing ";	slBeep(G3, 2);
		std::cout << "to ";		slBeep(F3, 3);
		std::cout << "grab ";	slBeep(Gsharp3, 2);
		std::cout << "your ";	slBeep(F3, 2);
		std::cout << "prize.";	slBeep(G3, 1.5f);
		std::cout << " ";		slBeep();
		std::cout << "\n";
		printDriver();
		std::cout << "They ";	slBeep(Gsharp3, 2);
		std::cout << "work ";	slBeep(F3);
		std::cout << "for ";	slBeep(G3, 3);
		std::cout << "the ";	slBeep(G3, 3);
		std::cout << "mer";		slBeep(Gsharp3);
		std::cout << "ce";		slBeep(F3, 3);
		std::cout << "na";		slBeep(F3);
		std::cout << "ry.";		slBeep(Fsharp3);
		std::cout << " ";		slBeep(R, 2);
		std::cout << "The ";	slBeep(F3, 2);
		std::cout << "mas";		slBeep(Gsharp3, 2);
		std::cout << "ked ";	slBeep(F3, 2);
		std::cout << "man.";	slBeep(G3, 1.5f);
		slBeep(R, 0.25f);

		std::cout << "\n";
		printCIA();
		std::cout << "Bane?";	slBeep(A3, 0.5f);
		slBeep(R, 0.25f);

		std::cout << "\n";
		printCIA();
		std::cout << "Get ";	slBeep(Gsharp3, 2);
		std::cout << "'em ";	slBeep(F3, 3);
		std::cout << "on ";		slBeep(E3, 2);
		std::cout << "board, ";	slBeep(D3);
		std::cout << "I'll ";	slBeep(A3, 2);
		std::cout << "call ";	slBeep(G3, 2);
		std::cout << "it ";		slBeep(Fsharp3, 2);
		std::cout << "in.";		slBeep(G3, 2);
		slBeep(R, 0.25f);
		
		std::cout << "\n[The commuter plane struggles over snow-capped mountains.]";
		slBeep(A2, 0.25f);
		
		std::cout << "\n";
		printCIA();
		std::cout << "The ";	slBeep(F3, 3);
		std::cout << "flight ";	slBeep(Fsharp3);
		std::cout << "plan ";	slBeep(F3);
		std::cout << "I ";		slBeep(F3, 3);
		std::cout << "just ";	slBeep(E3, 2);
		std::cout << "filed ";	slBeep(G3);
		std::cout << "with ";	slBeep(Fsharp3, 2);
		std::cout << "the ";	slBeep(F3, 2);
		std::cout << "A";		slBeep(E3, 3);
		std::cout << "gen";		slBeep(F3, 2);
		std::cout << "cy ";		slBeep(E3, 2);
		std::cout << "lists ";	slBeep(E3);
		std::cout << "me";		slBeep(E3);
		std::cout << ", ";		slBeep(R);
		std::cout << "my ";		slBeep(G3, 2);
		std::cout << "men";		slBeep(Gsharp3, 2);
		std::cout << ",";		slBeep(R);
		std::cout << "\n";		printCIA();
		std::cout << "Doc";		slBeep(F3, 2);
		std::cout << "tor ";	slBeep(E3, 2);
		std::cout << "Pa";		slBeep(Fsharp3);
		std::cout << "vel ";	slBeep(E3, 2);
		std::cout << "here";	slBeep(E3);
		std::cout << ", ";		slBeep(R);
		std::cout << "but ";	slBeep(Fsharp3, 2);
		std::cout << "on";		slBeep(G3, 2);
		std::cout << "ly ";		slBeep(Gsharp3, 2);
		std::cout << "one ";	slBeep(Gsharp3);
		std::cout << "of ";		slBeep(F3, 2);
		std::cout << "you.";	slBeep(Gsharp3);
		std::cout << " ";		slBeep(R, 0.5f);

		std::cout << "\n";		printCIA();
		std::cout << "FIRST ";	slBeep(G3);
		std::cout << "ONE ";	slBeep(G3, 2);
		std::cout << "TO ";		slBeep(Gsharp3, 2);
		std::cout << "TALK ";	slBeep(Gsharp3);
		std::cout << "GETS ";	slBeep(Fsharp3, 2);
		std::cout << "TO ";		slBeep(G3, 2);
		std::cout << "STAY ";	slBeep(Gsharp3);
		std::cout << "ON ";		slBeep(Gsharp3, 2);
		std::cout << "MY ";		slBeep(Fsharp3, 2);
		std::cout << "AIR";		slBeep(Gsharp3, 2);
		std::cout << "CRAFT!";	slBeep(G3);
		
		
		slBeep(R, 0.25f);

		//slBeep(R, 0.001f);

		mspb = previousmspb;
		return 0;
	}
	static void printCIA()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "       \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << "\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7); std::cout << "       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << " \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "      "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16); std::cout << "       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << "\xDC\xDF \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8); std::cout << "       \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << "\xDF\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 3);
		std::cout << "       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 3); std::cout << "     \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 3);
		std::cout << " \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 3);
		std::cout << "\xDC     "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 3); std::cout << "";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1 * 16 + 3);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << " \xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 * 16 + 11);
		std::cout << "\xDC\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "   \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDC  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16); std::cout << "  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 3);
		std::cout << "\xDB     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16); std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 3);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "    \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16);
		std::cout << "     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 * 16 + 1);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "      \xDB"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); std::cout << "";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16);
		std::cout << "     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDC      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDC"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8); std::cout << "";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 3);
		std::cout << "      \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "       "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); std::cout << "\xDB    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 3);
		std::cout << "      \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8); std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDC\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 3);
		std::cout << "\xDB     \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "     \xDC\xDB"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); std::cout << "";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 1);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 3);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << " \xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << " \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7); std::cout << "  \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDF\xDB\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << "\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDF \xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDF   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8); std::cout << "    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "    "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7); std::cout << "    \xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB\xDB \xDB\xDC\xDB  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7); std::cout << "   \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "  \xDC\xDC\xDB\xDF\xDC\xDB\xDF\xDB\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16); std::cout << "   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "   \xDB\xDB\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDB \xDF\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "   "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16); std::cout << "   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "  \xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB  \xDB \xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7); std::cout << "  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "  \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF    \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB\xDB\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7); std::cout << "  \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDB  "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7); std::cout << "  \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "      \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7); std::cout << " \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDF\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "      \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB\xDB\xDC\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " "; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0); std::cout << "\n"; SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16); std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "  \xDC\xDF\xDB\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "       \xDB\xDB\xDB\xDB\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "\n";
	}
	static void printDriver()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "        \xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDB\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "                 \n     \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 1);
		std::cout << "\xDB\xDF\xDF \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << "\xDF\xDC \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC           \n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDF     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDB  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDB\xDF\xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDC         \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << " \xDF   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 7);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF\xDC \xDC \xDB  \xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDC        \n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF\xDF\xDF\xDF  \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDC    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF   \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDC       \n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC  \xDF\xDF\xDF \xDC\xDC\xDC     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << "  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC        ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDC      \n  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC\xDC\xDC\xDB\xDB\xDF\xDB\xDB\xDF\xDF    \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDF\xDF\xDB\xDB      \n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC\xDB\xDF\xDB\xDF     \xDF      \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 12);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "      \n \xDF  \xDC\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 4);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC\xDC   \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "      \n \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC\xDC\xDC\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDB\xDB\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDB\xDB\xDB\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16);
		std::cout << "  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 4);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "      \n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << " \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << " \xDF\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << " \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDB      \n  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << " \xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDF\xDF\xDF       \xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "       \n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "   \xDC\xDC\xDC        \xDF\xDF\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDB\xDB\xDC     \n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << " \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 15);
		std::cout << "\xDF  \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << " \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << " \xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC\xDC   \xDC  \xDB\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "     \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDC \n    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << " \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDC\xDC\xDC\xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << " \xDC\xDF\xDC \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDC    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\n     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16);
		std::cout << "   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDB\xDC\xDC\xDF\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\n     \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDC\xDC  \xDF\xDB\xDB\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << " \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDB\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC  \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 3);
		std::cout << "\n     \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << "\xDB  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF  \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDF\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << " \xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16);
		std::cout << " \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDB  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\n     \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "  \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDC\xDB\xDB\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF \xDC\xDB\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF   \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDB  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\n      \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDC\xDB\xDB    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDF   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDF\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\n      \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "  \xDB\xDB\xDB\xDB\xDB\xDB\xDC\xDC\xDC\xDC \xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << " \xDF\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 3);
		std::cout << "\n     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "    \xDF     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF\xDF\xDF\xDF\xDF\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDF\xDC   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\n     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "   \xDF        ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\n    \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << " \xDF\xDC                ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC         ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 * 16);
		std::cout << " \n";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	static void printPavel()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "            \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 4);
		std::cout << "\xDC\xDC\xDC                 \n           ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "          \xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "           \n         \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF                ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDC\xDC       \n       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF                      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 4);
		std::cout << "\xDC    \n       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "                         \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 6);
		std::cout << "\xDC  \n     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDF                            ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 4);
		std::cout << "\xDB \n     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "     \xDF   \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC\xDC                ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 6);
		std::cout << "\xDC\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDF         ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "  \xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "                \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "            \xDB\xDB\xDB\xDF    \xDC\xDC\xDC\xDC\xDC\xDB\xDB\xDC\xDC\xDC  \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\n\xDF   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDB\xDB     \xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC\xDC\xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDC\xDC\xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDC  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "  \xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << " \xDC\xDB\xDB\xDC\xDC\xDB\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "     \xDC\xDC    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDF    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDB\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDF      \xDC    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << " \xDC\xDC\xDC \xDB\xDB    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << " \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDC\xDB\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "      \xDB\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC    \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 8);
		std::cout << "\xDF\xDF\xDC\xDB\xDC\xDC\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF  \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "      \xDB\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC\xDC   \xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDB\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF     \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "      \xDF\xDB\xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC  \xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDF       \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "      \xDF\xDB\xDF\xDF\xDF\xDF\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDF        \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "          \xDF\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF \xDF\xDB\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF         \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "        \xDF\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF          \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "          \xDC\xDC\xDB\xDB\xDC\xDF\xDF\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 4);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 4);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "            \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "          \xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDC\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDF             \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "           \xDB\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDC    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "             \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "              \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 * 16 + 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDF    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n                       \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n                      \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

	// code page 437 only
	static void printPJSaltLarge()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "              \xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDC      \n          \xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC    \n      \xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB   \n   \xDC\xDB\xDB\xDB\xDB\xDF\xDF\xDF\xDB\xDB\xDF\xDB\xDB\xDD\xDB\xDB\xDB\xDF\xDF\xDF\xDB\xDB\xDB\xDB  \n  \xDE\xDF\xDB\xDB\xDB\xDB\xDD\xDF\xDB\xDB\xDD\xDF\xDE\xDB\xDD\xDB\xDB\xDB\xDB\xDD\xDB\xDB\xDB\xDB\xDB\xDD \n  \xDB\xB1\xB1\xDF\xDB\xDB\xDF\xDF\xDE\xDB\xDE\xDB\xDD\xDB\xDD\xDF\xDF\xDB\xDB\xDD\xDB\xDB\xDB\xDB\xDB\xDB \n  \xDB\xB1\xB1\xB1\xB1\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDD \n   \xDD\xB1\xB1\xB1\xB1\xDB\xDB\xDB\xDB\xDB\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xDB\xDB\xDB\xDB\xDB\xDB\xDF  \n   \xDF\xDC\xB2\xB2\xB2\xB1\xDB\xDB\xDB\xB0\xB0\xB0\xB0\xB0\xB0\xDB\xDB\xDB\xDB\xDB\xDF\xDF    \n    \xDF\xB0\xB2\xB2\xB1\xDE\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDF\xDF        \n     \xB0\xB0\xB1\xB1\xDE\xDB\xDB\xDB\xDB\xDB\xDF\xDF            \n  \xB0\xB0\xB0\xB0\xB0\xDF\xDF\xDF\xDF\xDF\xDF                \n   \xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0                  \n";
	}
	// code page 437 only
	static void printLeToucan()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "        \xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16);
		std::cout << "\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDC\xDC\xDB\xDB\xDB\xDC                 \n     \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16);
		std::cout << "\xDF\xDF       \xDE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " \xDF\xDB\xDB\xDD                \n   \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16);
		std::cout << "\xDF    \xDC\xDC\xDB\xDB\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDD\xDF\xDF \xDF\xDB                \n  \xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16);
		std::cout << "  \xDC\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 12);
		std::cout << "\xB1\xB1\xB1\xB1\xB1";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16);
		std::cout << "\xDC\xDE";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "    \xDB\xDD               \n \xDE\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16);
		std::cout << "\xDF\xDC\xDF\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDF\xDF\xDF\xDF\xDD     \xDE\xDB\xDC              \n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16);
		std::cout << "\xDB\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDF\xDF        \xDD    \xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC         \n             \xDE    \xDE\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC      \n     le      \xDE    \xDE\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC    \n    toucan    \xDF\xDC   \xDE\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC  \n      has       \xDF\xDC\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDC \n     "; std::cout << "arrived          \xDB\xDF\xDB\xDB\xDB\xDB\xDB\xDB       \n";
	}

	static void printIceKirby()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "    \xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDC\xDC   \n  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 11);
		std::cout << "\xDF       \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDB  \n \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDF      \xDC \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << " \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << " \n\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 11);
		std::cout << "\xDF       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDB \xDB   \xDB\n\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 11);
		std::cout << "\xDC  \xDC \xDF\xDF    \xDF\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDB\n \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "     \xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 11);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDB\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDF\n  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDF\xDF\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDC\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDC \n \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDC\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDF\xDF\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 9);
		std::cout << "\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 9);
		std::cout << "\xDF\n";
	}
	static void printShrek()
	{
		std::cout << "        ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDC\xDC\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC\n     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDF    \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF\xDC\xDC\xDC\xDC\xDF\xDF\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDB\xDC\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDF      \xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC    \xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC \xDC\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "  \xDC\xDF     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF\xDF\xDF\xDB\xDF\xDF\xDF\xDB\xDB\xDB\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDB\xDC\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF\xDF\n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDF    \xDB\xDF\xDF  \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF\xDF\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF\n\xDF    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDC\xDF\xDF\xDC \xDC\xDF\xDF\xDC\xDF \xDC\xDB  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC\n       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF \xDF\xDC\xDC\xDF \xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF\xDF   \xDF\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "     \xDC\xDF\xDC\xDF\xDC   \xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDB\xDF   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "    \xDF\xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << " \xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC \xDC\xDF\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDB\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC   \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF \xDC\xDF\xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << " \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << " \xDB\xDB\xDB\xDB\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDB   \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "    \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDB\xDB\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDF\xDC\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC  \xDC   \xDF  \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "    \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDB\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDB \xDB\xDB\xDB\xDB\xDF \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC\xDF\xDB\xDB\xDB\xDB\xDB\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDB\xDC\xDF\xDB\xDB\xDB\xDB\xDF\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF\xDF\xDB\xDB\xDB\xDB\xDF\xDF \xDC  \xDB \n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDB    \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDF\xDC\xDF\xDB\xDB\xDC\xDB\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "     \xDF\xDF  \xDC\xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF\xDF\xDC\xDC  \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC\xDB\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC\xDB\xDB\xDB\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC\xDC\xDC \xDB \xDF \xDC\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 6);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC\n\xDB\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDB\xDB\xDB \xDC\xDB\xDB\xDB\xDB\xDB\xDF\xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDF\xDC       \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF\xDB\xDC\n\xDC\xDF\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF\xDB\xDC\xDF\xDB\xDB\xDB\xDB\xDB\xDC\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDC\xDF\xDC\xDF\xDC\xDB\xDC\xDB\xDC\xDB\xDB\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << " \xDB\xDB\n\xDF\xDC\xDF\xDB\xDB\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF\xDC\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDB\xDF\xDF\xDF \xDC\xDF\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << " \xDB\xDB\xDB\n  \xDF\xDC\xDF\xDB\xDF\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF\xDF\xDB\xDC\xDC  \xDF\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 * 16 + 2);
		std::cout << "\xDB\xDC\xDC\xDF\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC\xDB\xDF\xDB \n    \xDF \xDF \xDF\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		std::cout << "\xDF\xDF\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF\xDF \xDF\n";
	}
	static void printApertureLogo(){ std::cout << "\n              .,-:;//;:=,\n          . :H@@@MM@M#H/.,+%;,\n       ,/X+ +M@@M@MM%=,-%HMMM@X/,\n     -+@MM; $M@@MH+-,;XMMMM@MMMM@+-\n    ;@M@@M- XM@X;. -+XXXXXHHH@M@M#@/.\n  ,%MM@@MH ,@%=            .---=-=:=,.\n  =@#@@@MX .,              -%HX$$%%%+;\n =-./@M@M$                  .;@MMMM@MM:\n X@/ -$MM/                    .+MM@@@M$\n,@M@H: :@:                    . =X#@@@@-\n,@@@MMX, .                    /H- ;@M@M=\n.H@@@@M@+,                    %MM+..%#$.\n /MMMM@MMH/.                  XM@MH; =;\n  /%+%$XHH@$=              , .H@@@@MX,\n   .=-------.            -%H.,@@@@@MX,\n   .%MM@@@HHHXX$$$%+- .:$MMX =M@@MM%.\n     =XMMM@MM@MM#H;,-+HMM@M+ /MMMX=\n       =%@M@M#@$-.=$@MM@@@M; %M%=\n         ,:+$+-,/H#MMMMMMM@= =,\n               =++%%%%+/:-.\n"; }
	static void printKappa(){ std::cout << "\x2"; }
	static void printSMLDie()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << " \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDF    \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << " \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16);
		std::cout << " \xDC\xDB\xDC\xDF  \xDF\xDC\xDB\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " \xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16);
		std::cout << " \xDF\xDF\xDF\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDB\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << "\xDF\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16);
		std::cout << " \xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "   \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 15);
		std::cout << "\xDF  \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDB   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "   \xDF\xDF\xDF\xDF\xDF\xDF   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "\n";
	}
	static void printSMBMarioPeachColour()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		std::cout << "    \xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 * 16 + 15);
		std::cout << "    \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		std::cout << "\n   \xDB\xDB\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 * 16 + 15);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		std::cout << "\xDC\xDC\xDC\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 4);
		std::cout << "\xDF\xDF\xDB  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		std::cout << " \xDF\xDB\xDB\xDC\xDC\n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << " \xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 4);
		std::cout << "  \xDB\xDB   \xDC    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "\n  \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 4);
		std::cout << "\xDC    \xDF\xDB\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		std::cout << "        \xDB\xDC\xDB\xDB\xDC\xDB\n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		std::cout << "   \xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 4);
		std::cout << "     \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		std::cout << "\xDF\xDF       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16);
		std::cout << "\xDF        \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		std::cout << "\n    \xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 * 16 + 12);
		std::cout << "\xDB    \xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		std::cout << "\xDC        ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6 * 16 + 14);
		std::cout << " \xDC\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 6);
		std::cout << " \xDF\xDB\xDF\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		std::cout << "\n  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 * 16 + 12);
		std::cout << "   \xDB    \xDB   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		std::cout << "\xDC      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16);
		std::cout << "\xDC      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 6);
		std::cout << "\xDF \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDC\n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 * 16 + 12);
		std::cout << "   \xDB\xDB    \xDB\xDB   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		std::cout << "\xDC     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 12);
		std::cout << " \xDB\xDB\xDF   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 * 16 + 6);
		std::cout << "\xDC\xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "\n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 * 16);
		std::cout << "    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12 * 16 + 14);
		std::cout << " \xDC    \xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9 * 16);
		std::cout << "    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xE6);
		std::cout << "\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xED);
		std::cout << "\xDC  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6D);
		std::cout << "\xDC   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "\n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
		std::cout << "\xDB\xDB\xDB\xDB        \xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6F);
		std::cout << " \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xDE);
		std::cout << " \xDF\xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xDF);
		std::cout << "\xDC\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		std::cout << "\xDB\xDB\n  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xCF);
		std::cout << "\xDB\xDB\xDF        \xDF\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF);
		std::cout << "     \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFD);
		std::cout << "       \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x6D);
		std::cout << "\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xC);
		std::cout << "\n  \xDC\xDB\xDB\xDB\xDB\xDB\xDF\xDF\xDB\xDB\xDB\xDB\xDB\xDC       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xDB);
		std::cout << "\xDF\xDF    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD6);
		std::cout << "\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD);
		std::cout << "\xDC\n  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xC0);
		std::cout << "     \xDB\xDB\xDB\xDB     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xD);
		std::cout << "      \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x40);
		std::cout << "    \xDB\xDB\xDB\xDB    \xDB\xDB\xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFD);
		std::cout << "\xDF\xDF\xDF\xDF      \xDF\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\n\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x40);
		std::cout << "      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << " \xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x40);
		std::cout << "      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDC\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xDF);
		std::cout << "\xDF\xDF\xDF\xDF\xDF    \xDF\xDF\xDF\xDF\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "\xDC\xDC\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDC\n";
		for (int b0 = 0; b0 < 5; b0++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			std::cout << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
			std::cout << "     ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
			std::cout << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			std::cout << " ";
		}
		std::cout << "\n";
		for (int b0 = 0; b0 < 5; b0++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF0);
			std::cout << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
			std::cout << "     ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x80);
			std::cout << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			std::cout << " ";
		}
		std::cout << "\n";
		for (int b0 = 0; b0 < 5; b0++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xF8);
			std::cout << "\xDC";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x78);
			std::cout << "\xDC\xDC\xDC\xDC\xDC";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x88);
			std::cout << "\xDC";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << " ";
		}
		std::cout << "\n";
	}

    static LPDWORD t;
	static HANDLE t0;

	// AntiTempo will only be applied to National Anthems. GSTQ is typically played faster than other NAs so I'd recommend calling it with 600
    void play(TrackName a, int NatAnthemMSPB = 750)
    {
		int*b = new int(NatAnthemMSPB);
        try { TerminateThread(t0, 0); }
		catch (...) {}
		switch (a)
		{
		case SMBDie:
			t0 = CreateThread(NULL, 0, musicSMBDie, 0, 0, t);
			break;
		case SMBWin:
			t0 = CreateThread(NULL, 0, musicSMBWin, 0, 0, t);
			break;
		case NSMBBGM:
			t0 = CreateThread(NULL, 0, musicNSMBBGM, 0, 0, t);
			break;
		case SMDDie:
			t0 = CreateThread(NULL, 0, musicSMBDieBass, 0, 0, t);
			break;
		case SMDWin:
			t0 = CreateThread(NULL, 0, musicSMDWin, 0, 0, t);
			break;
		case Sonic1GHZ:
			t0 = CreateThread(NULL, 0, musicS1GHZ, 0, 0, t);
			break;
		case ReconstructingMoreScience:
			t0 = CreateThread(NULL, 0, musicReconstructScience, 0, 0, t);
			break;
		case YourPreciousMoon:
			t0 = CreateThread(NULL, 0, musicPreciousMoon, 0, 0, t);
			break;
		case MagicRoundabout:
			t0 = CreateThread(NULL, 0, musicMagicRnd, 0, 0, t);
			break;
		case AllStar:
			t0 = CreateThread(NULL, 0, musicAllStar, 0, 0, t);
			break;
		case Umaru:
			t0 = CreateThread(NULL, 0, musicUMR, 0, 0, t);
			break;
		case Futurama:
			t0 = CreateThread(NULL, 0, musicFut, 0, 0, t);
			break;
		case PinkPanther:
			t0 = CreateThread(NULL, 0, musicPP, 0, 0, t);
			break;
		case DarkKnightRises:
			t0 = CreateThread(NULL, 0, musicDarkKnight, 0, 0, t);
			break;
		case SMBCastleWin:
			t0 = CreateThread(NULL, 0, musicSMBCastleWin, 0, 0, t);
			break;
		case SMBCastleDie:
			t0 = CreateThread(NULL, 0, musicSMBCastleDie, 0, 0, t);
			break;
		case NARussia:
			t0 = CreateThread(NULL, 0, musicStateAnthemOfTheRussianFederation, b, 0, t);
			break;
		case NAUSA:
			t0 = CreateThread(NULL, 0, musicStarSpangledBanner, b, 0, t);
			break;
		case NACommonwealth:
			t0 = CreateThread(NULL, 0, musicGSTQ, b, 0, t);
			break;
		case NALichtenstein:
			t0 = CreateThread(NULL, 0, musicGSTK, b, 0, t);
			break;
		case Dangermouse:
			t0 = CreateThread(NULL, 0, musicDM, 0, 0, t);
			break;
		default:
			TerminateThread(t0, 0);
			break;
		}
    }

	// Import UltraStar/UltraStarDX/Performous/MyLittleKaraoke lyric text files.
	//
	// A lot of these files use C1 as a base and need pitching up.
	// If a character displays incorrectly, change it in the txt file to be the Unicode character with the code point which corresponds to the code point of the correct character in the code page installed on your machine.
	void play(char* file, note basenote = C3, float tempomultiplier = 1.0f)
	{
		float previousmspb = mspb;
		//mspb = MillisecondsPerBeat;

		std::ifstream inFile;
		inFile.open(file);
		
		if (!inFile.good())
		{
			std::cout << "not there";
		}
		else
		{
			std::vector<int> startbeat;
			std::vector<int> duration;
			std::vector<note> pitch;
			std::vector<std::string> lyric;

			std::string input;
			
			int _startbeat;
			int _duration;
			int _pitch;

			while (!inFile.eof())
			{
				std::getline(inFile, input);

				if (input.substr(0, 1).compare(":") == 0 || input.substr(0, 1).compare("*") == 0 || input.substr(0, 1).compare("F") == 0) // note or gold note or 'freestyle syllable'
				{
					input = input.substr(input.find_first_of(' ') + 1);
					_startbeat = atoi(input.substr(0, input.find_first_of(' ')).c_str());
					startbeat.push_back(_startbeat);
					input = input.substr(input.find_first_of(' ') + 1);
					_duration = atoi(input.substr(0, input.find_first_of(' ')).c_str());
					duration.push_back(_duration);
					input = input.substr(input.find_first_of(' ') + 1);
					_pitch = atoi(input.substr(0, input.find_first_of(' ')).c_str());
					pitch.push_back((note)(_pitch + (int)basenote));
					input = input.substr(input.find_first_of(' ') + 1);
					lyric.push_back(input);
				}
				else if (input.substr(0, 1).compare("-") == 0) // line breaks
				{
					input = input.substr(input.find_first_of(' ') + 1);
					_startbeat = atoi(input.substr(0, input.find_first_of(' ')).c_str());
					startbeat.push_back(_startbeat);
					duration.push_back(1);
					pitch.push_back(REST);
					lyric.push_back("\n");
				}
				else // debug out the comments
				{
					if (input.length() > 4)
						if (input.substr(0, 4).compare("#BPM") == 0)
							mspb = (int)(atoi(input.substr(5).c_str()) * 50 / 60) / tempomultiplier;
					//std::cout << input << "\n";
				}
			}
			inFile.close();

			std::vector<param> toBeep;

			param temp;

			if (startbeat[0] > 0)
				for (int s : startbeat)
					s -= startbeat[0];

			temp.f = pitch[0];
			temp.inverseFractionOfCrotchet = 2.0f / duration[0];
			temp.line = lyric[0];

			toBeep.push_back(temp);

			for (int b0 = 1; b0 < startbeat.size(); b0++)
			{
				if (startbeat[b0 - 1] + duration[b0 - 1] != startbeat[b0]) // if the previous note did not last until the current note, buffer it with a REST
				{
					temp.f = REST;
					temp.inverseFractionOfCrotchet = 2.0f / (float)(startbeat[b0] - (startbeat[b0 - 1] + duration[b0 - 1]));
					temp.line = "";

					toBeep.push_back(temp);
				}
				temp.f = pitch[b0];
				temp.inverseFractionOfCrotchet = 2.0f / duration[b0];
				temp.line = lyric[b0];

				toBeep.push_back(temp);
			}
			for (param p0 : toBeep)
			{
				slBeep(p0);
			}
		}
		mspb = previousmspb;
	}
};
#endif

float SoundLib::mspb = 600;
SoundLib* SoundLib::mInstance = NULL;
LPDWORD SoundLib::t = 0;
HANDLE SoundLib::t0 = NULL;