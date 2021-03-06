﻿#ifndef BEEP_H
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
// usage example:
//	SoundLib::Instance()->play(SoundLib::AllStar); // play automatically puts the song on a new thread, calling a musicX method directly will hang your program until it finishes
//  WaitForSingleObject(SoundLib::t0, INFINITE);
//
//  SoundLib::Instance()->play("notes.txt", SoundLib::C3, 150); // plays from an UltraStar or compatible text file. does not start song on new thread or display lyrics (use karaoke branch instead for lyrics)
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
	enum note { BELL, REST, R, C1, Csharp1, D1, Dsharp1, E1, F1, Fsharp1, G1, Gsharp1, A1, Asharp1, B1, C2, Csharp2, D2, Dsharp2, E2, F2, Fsharp2, G2, Gsharp2, A2, Asharp2, B2, C3, Csharp3, D3, Dsharp3, E3, F3, Fsharp3, G3, Gsharp3, A3, Asharp3, B3, C4, Csharp4, D4, Dsharp4, E4, F4, Fsharp4, G4, Gsharp4, A4, Asharp4, B4, C5, Csharp5, D5, Dsharp5, E5, F5, Fsharp5, G5, Gsharp5, A5, Asharp5, B5, C6, C, Csharp, D, Dsharp, E, F, Fsharp, G, Gsharp, A, Asharp, B };
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

	static struct param{ note f; float inverseFractionOfCrotchet; };
	static void slBeep(param slBeepParameters){ slBeep(slBeepParameters.f, slBeepParameters.inverseFractionOfCrotchet); }

	enum TrackName { SMBDie, SMBWin, NSMBBGM, SMDDie, SMDWin, Sonic1GHZ, ReconstructingMoreScience, YourPreciousMoon, MagicRoundabout, AllStar, Umaru, Futurama, PinkPanther, DarkKnightRises, SMBCastleWin, SMBCastleDie, NARussia, NACommonwealth, NAUSA, NALichtenstein, Dangermouse, Flinstones, Stop };

	static DWORD WINAPI musicSMBDie(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 600.0f; slBeep(B3, 4); slBeep(F4, 2); slBeep(F4, 4); slBeep(F4, 3); slBeep(E4, 3); slBeep(D4, 3); slBeep(C4, 4); slBeep(E3, 2); slBeep(E3, 4); slBeep(C3, 2); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicSMBWin(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 600.0f; slBeep(G2, 3); slBeep(C3, 3); slBeep(E3, 3); slBeep(G3, 3); slBeep(C4, 3); slBeep(E4, 3); slBeep(G4, 1); slBeep(E4, 1); slBeep(Gsharp2, 3); slBeep(C3, 3); slBeep(Dsharp3, 3); slBeep(Gsharp3, 3); slBeep(C4, 3); slBeep(Dsharp4, 3); slBeep(Gsharp4, 1); slBeep(Dsharp4, 1); slBeep(Asharp2, 3); slBeep(D3, 3); slBeep(F3, 3); slBeep(Asharp3, 3); slBeep(D4, 3); slBeep(F4, 3); slBeep(Asharp4, 1); slBeep(Asharp4, 3); slBeep(Asharp4, 3); slBeep(Asharp4, 3); slBeep(C5, 0.5f); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicSMBCastleDie(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 550.0f; slBeep(C4, 2); slBeep(R, 2); slBeep(G3, 2); slBeep(R, 2); slBeep(E3, 1); slBeep(A3, 1.5f); slBeep(B3, 1.5f); slBeep(A3, 1.5f); slBeep(Gsharp3, 1.5f); slBeep(Asharp3, 1.5f); slBeep(Gsharp3, 1.5f); slBeep(G3, 4); slBeep(F3, 4); slBeep(G3, 0.5f); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicSMBCastleWin(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 400.0f; slBeep(C4, 2); slBeep(G3, 2); slBeep(E3, 2); slBeep(C4, 2); slBeep(G3, 2); slBeep(E3, 2); slBeep(C4, 0.25f); slBeep(Csharp4, 2); slBeep(Gsharp3, 2); slBeep(F3, 2); slBeep(Csharp4, 2); slBeep(Gsharp3, 2); slBeep(F3, 2); slBeep(Csharp4, 0.25f); slBeep(Dsharp4, 2); slBeep(Asharp3, 2); slBeep(G3, 2); slBeep(Dsharp4, 2); slBeep(Asharp3, 2); slBeep(G3, 2); slBeep(Dsharp4, 0.5f); slBeep(F4, 2); slBeep(F4, 2); slBeep(F4, 2); slBeep(G4, 0.25f); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicNSMBBGM(LPVOID lpParam = 0)
        {
            while (true)
            {
                mspb = 300.0f;
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
	static DWORD WINAPI musicSMBDieBass(LPVOID lpParam = 0) { mspb = 600.0f; slBeep(G2, 2); slBeep(R, 4); slBeep(G2, 4); slBeep(G2, 3); slBeep(A2, 3); slBeep(B2, 3); slBeep(C3, 2); slBeep(G2, 2); slBeep(C2, 2); return 0; }

	static DWORD WINAPI musicSMDWin(LPVOID lpParam = 0) { float previousmspb = mspb; mspb = 350.0f; slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3); slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3); slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3, 0.5f); slBeep(C5, 2); slBeep(B4, 2); slBeep(G4, 2); slBeep(A4, 0.2f); mspb = previousmspb; return 0; }
	static DWORD WINAPI musicS1GHZ(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; mspb = 400.0f;
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
            float previousmspb = mspb; mspb = 600.0f;
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
            float previousmspb = mspb; mspb = 600.0f;
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
        float previousmspb = mspb; mspb = 500.0f;
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
		float previousmspb = mspb; mspb = 600.0f;
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
		float previousmspb = mspb; mspb = 600.0f;
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
		float previousmspb = mspb; mspb = 660.0f;
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
		float previousmspb = mspb; mspb = 380.0f;

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

	// passing this an int* to change the mspb it is played at
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
	// contains one verse. play/wait three times for three verses. accepts int* mspb
	static DWORD WINAPI musicStarSpangledBanner(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; if (lpParam != 0) mspb = *(int*)lpParam;

		slBeep(F, 2); slBeep(D, 2);
		slBeep(Asharp2); slBeep(D); slBeep(F);
		slBeep(Asharp, 0.5f); slBeep(D4, 2); slBeep(C4, 2);
		slBeep(Asharp); slBeep(D); slBeep(E);
		slBeep(F, 0.5f); slBeep(F, 2); slBeep(F, 2);
		slBeep(D4); slBeep(C4); slBeep(Asharp);
		slBeep(A, 0.5f); slBeep(G, 2); slBeep(A, 2);
		slBeep(Asharp); slBeep(Asharp); slBeep(F);
		slBeep(D); slBeep(Asharp2); slBeep(F, 2); slBeep(D, 2);
		slBeep(Asharp2); slBeep(D); slBeep(F);
		slBeep(Asharp, 0.5f); slBeep(D4, 2); slBeep(C4, 2);
		slBeep(Asharp); slBeep(D); slBeep(E);
		slBeep(F, 0.5f); slBeep(F, 2); slBeep(F, 2);
		slBeep(D4); slBeep(C4); slBeep(Asharp);
		slBeep(A, 0.5f); slBeep(G, 2); slBeep(A, 2);
		slBeep(Asharp); slBeep(Asharp); slBeep(F);
		slBeep(D); slBeep(Asharp2); slBeep(D4, 2); slBeep(D4, 2);
		slBeep(D4); slBeep(Dsharp4); slBeep(F4);
		slBeep(F4, 0.5f); slBeep(Dsharp4, 2); slBeep(D4, 2);
		slBeep(C4); slBeep(D4); slBeep(Dsharp4);
		slBeep(Dsharp4, 0.5f); slBeep(Dsharp4);
		slBeep(D4); slBeep(C4); slBeep(Asharp);
		slBeep(A, 0.5f); slBeep(G, 2); slBeep(A, 2);
		slBeep(Asharp); slBeep(D); slBeep(E);
		slBeep(F, 0.5f); slBeep(F);
		slBeep(Asharp); slBeep(Asharp); slBeep(Asharp, 2); slBeep(A, 2);
		slBeep(G); slBeep(G); slBeep(G);
		slBeep(C4); slBeep(Dsharp4, 2); slBeep(D4, 2); slBeep(C4, 2); slBeep(Asharp, 2);
		slBeep(Asharp); slBeep(A); slBeep(F, 2); slBeep(F, 2);
		slBeep(Asharp, 0.66f); slBeep(C4, 2); slBeep(D4, 2); slBeep(Dsharp4, 2);
		slBeep(F4, 0.5f); slBeep(Asharp, 2); slBeep(C4, 2);
		slBeep(D4, 0.66f); slBeep(Dsharp4, 2); slBeep(C4);
		slBeep(Asharp, 0.5f);

		mspb = previousmspb;
		return 0;
	}
	// contains one verse. play/wait two times for two verses. accepts int* mspb.
	static DWORD WINAPI musicGSTQ(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; if (lpParam != 0) mspb = *(int*)lpParam;

		slBeep(G); slBeep(G); slBeep(A);
		slBeep(Fsharp, 0.66f); slBeep(G, 2); slBeep(A);
		slBeep(B); slBeep(B); slBeep(C4);
		slBeep(B, 0.66f); slBeep(A, 2); slBeep(G);
		slBeep(A); slBeep(G); slBeep(Fsharp);
		slBeep(G, 0.33f);

		slBeep(D4); slBeep(D4); slBeep(D4);
		slBeep(D4, 0.66f); slBeep(C4, 2); slBeep(B);
		slBeep(C4); slBeep(C4); slBeep(C4);
		slBeep(C4, 0.66f); slBeep(B, 2); slBeep(A);
		slBeep(B); slBeep(C4, 2); slBeep(B, 2); slBeep(A, 2); slBeep(G, 2);
		slBeep(B, 0.66f); slBeep(C4, 2); slBeep(D4);
		slBeep(E4, 2); slBeep(C4, 2); slBeep(B); slBeep(A);
		slBeep(G, 0.33f);

		mspb = previousmspb;
		return 0;
	}

	static DWORD WINAPI musicAllStar(LPVOID lpParam = 0)
        {
            float previousmspb = mspb; mspb = 550.0f;
			
            slBeep(Fsharp);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(B);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);

            
            slBeep(Fsharp, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Dsharp);
            
            slBeep(Csharp, 0.666f);
            slBeep();

            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(B);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Csharp4);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Gsharp);
            
            slBeep(Dsharp, 0.666f);
            slBeep();

            
            slBeep(Fsharp, 1.333f);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 1.333f);

            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Fsharp, 1.333f);

            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(B, 4);
            
            slBeep(B, 4);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 1.333f);

            
            slBeep(Csharp, 4);
            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Dsharp, 4);
            
            slBeep(Csharp, 1.333f);

            //Bar 14
            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Dsharp4, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Dsharp4, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(B, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 1.333f);

            
            slBeep(Csharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp);
            slBeep(R, 1.333f);

            
            slBeep(Csharp, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Dsharp, 2);
            
            slBeep(Dsharp);
            slBeep();

            //Bar 18
            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Asharp, 0.8f);

            //Bar 20
            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Asharp, 0.8f);

            //Bar 22
            
            slBeep(Asharp);
            
            slBeep(Csharp4);
            
            slBeep(B, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 0.5f);

            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 0.8f);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Gsharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Dsharp, 0.333f);
            //
            //End chorus
            //

            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2); slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);

            
            slBeep(Csharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Fsharp, 4);

            
            slBeep(Csharp, 4);
            
            slBeep(Csharp, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(B, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Fsharp, 1.333f);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 2);
            
            slBeep(Dsharp, 4);
            
            slBeep(Dsharp, 2);

            
            slBeep(Csharp, 4);
            
            slBeep(Asharp, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Dsharp4, 1.333f);
            
            slBeep(Csharp, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 1.333f);

            
            slBeep(Csharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(B, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Dsharp, 2);
            
            slBeep(Dsharp, 1.333f);

            
            slBeep(Csharp, 4);
            
            slBeep(Dsharp4, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 1.333f);
            
            slBeep(Asharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 0.8f);

            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 2);
            
            slBeep(Dsharp, 1.333f);
            slBeep();

            //
            //Chorus
            //
            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Asharp, 0.8f);

            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Asharp, 0.8f);

            //Bar 22
            
            slBeep(Asharp);
            
            slBeep(Csharp4);
            
            slBeep(B, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 0.5f);

            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 0.8f);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Gsharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Dsharp, 0.333f);
            //
            //End chorus
            //

            //instrumental solo
            
            for (byte b0 = 0; b0 < 4; b0++)
            {
                slBeep(Csharp5); slBeep(Asharp4); slBeep(Gsharp4, 2); slBeep(Fsharp4, 2); slBeep(R, 2);
                slBeep(Asharp4); slBeep(B4, 2); slBeep(Asharp4); slBeep(Gsharp4, 2); slBeep(Fsharp4, 2); slBeep(Dsharp4, 2); slBeep(Csharp4, 2);
            }

            //
            //Chorus ed2
            //
            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Asharp, 0.8f);

            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Asharp, 0.8f);

            //Bar 54
            
            slBeep(Asharp);
            
            slBeep(Csharp4);
            
            slBeep(B, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Dsharp4, 2);
            
            slBeep(Fsharp4, 0.4f);

            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 0.666f);
            //
            //End chorus ed2
            //

            slBeep();

            
            slBeep(Fsharp);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(B);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);

            
            slBeep(Fsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Dsharp);
            
            slBeep(Csharp, 0.666f);
            slBeep();

            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 1.333f);
            
            slBeep(Csharp4);
            
            slBeep(Asharp, 4);
            
            slBeep(Gsharp, 4);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp);
            
            slBeep(Gsharp, 4);
            
            slBeep(Csharp4, 1.333f);
            
            slBeep(B, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(B, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(B, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Dsharp, 2);
            
            slBeep(Csharp, 2);
            
            slBeep(Dsharp, 2);
            
            slBeep(Csharp, 2);
            
            slBeep(Csharp4);
            
            slBeep(Asharp, 4);
            
            slBeep(Asharp, 4);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Gsharp);
            
            slBeep(Asharp, 0.4f);

            
            slBeep(Csharp4, 1.333f);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 1.333f);

            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Dsharp4, 4);
            
            slBeep(Csharp4, 1.333f);

            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(B, 4);
            
            slBeep(B, 4);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Asharp, 1.333f);

            
            slBeep(Csharp, 4);
            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Dsharp, 4);
            
            slBeep(Csharp, 1.333f);

            //Bar 69
            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Dsharp4, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Dsharp4, 2);
            
            slBeep(Asharp, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(B, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 1.333f);

            
            slBeep(Csharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp);
            slBeep(R, 1.333f);

            
            slBeep(Csharp, 4);
            
            slBeep(Dsharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 4);
            
            slBeep(Csharp4, 2);
            
            slBeep(Csharp4);
            slBeep();

            //Bar 73
            //
            //Chorus ed3
            //
            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Asharp, 0.8f);

            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 4);
            
            slBeep(Dsharp, 4);
            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Fsharp, 2);
            slBeep(R, 2);
            
            slBeep(Asharp);

            slBeep(Csharp, 2);
            //Bar 54
            
            slBeep(Asharp);
            
            slBeep(Csharp4);
            
            slBeep(B, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Dsharp4, 2);
            
            slBeep(Fsharp4, 2);

            
            slBeep(Gsharp4, 2);
            
            slBeep(Fsharp4, 0.666f);

            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);

            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 0.666f);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Gsharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Fsharp, 0.333f);

            slBeep(Csharp, 2);
            //Bar 81
            
            slBeep(Asharp);
            
            slBeep(Csharp4);
            
            slBeep(B, 2);
            
            slBeep(Csharp4, 2);
            
            slBeep(Dsharp4, 2);
            
            slBeep(Fsharp4, 2);

            
            slBeep(Gsharp4, 2);
            
            slBeep(Fsharp4, 0.666f);

            
            slBeep(Fsharp, 2);
            
            slBeep(Fsharp, 2);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp, 2);

            
            slBeep(Csharp4, 2);
            
            slBeep(Asharp, 0.666f);
            
            slBeep(Gsharp, 2);
            
            slBeep(Fsharp);
            
            slBeep(Gsharp, 2);
            
            slBeep(Asharp, 2);
            
            slBeep(Dsharp, 0.286f); // seven halfs

            mspb = previousmspb;
			return 0;
        }

	static DWORD WINAPI musicDarkKnight(LPVOID lpParam = 0)
	{
		float previousmspb = mspb; mspb = 400.0f;

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
		case NACommonwealth: case NALichtenstein:
			t0 = CreateThread(NULL, 0, musicGSTQ, b, 0, t);
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
	// A lot of these files use C1 as a base and need pitching up. Make MillisecondsPerBeat lower to make it play faster.
	//If a character displays incorrectly, change it in the txt file to be the Unicode character with the code point which corresponds to the code point of the correct character in the code page installed on your machine.
	void play(char* file, note basenote = C3, float tempomultiplier = 1.0f)
	{
		float previousmspb = mspb;

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
				}
				else if (input.substr(0, 1).compare("-") == 0) // line breaks
				{
					input = input.substr(input.find_first_of(' ') + 1);
					_startbeat = atoi(input.substr(0, input.find_first_of(' ')).c_str());
					startbeat.push_back(_startbeat);
					duration.push_back(1);
					pitch.push_back(REST);
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

			toBeep.push_back(temp);

			for (int b0 = 1; b0 < startbeat.size(); b0++)
			{
				if (startbeat[b0 - 1] + duration[b0 - 1] != startbeat[b0]) // if the previous note did not last until the current note, buffer it with a REST
				{
					temp.f = REST;
					temp.inverseFractionOfCrotchet = 2.0f / (float)(startbeat[b0] - (startbeat[b0 - 1] + duration[b0 - 1]));

					toBeep.push_back(temp);
				}
				temp.f = pitch[b0];
				temp.inverseFractionOfCrotchet = 2.0f / duration[b0];

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

float SoundLib::mspb = 600.0f;
SoundLib* SoundLib::mInstance = NULL;
LPDWORD SoundLib::t = 0;
HANDLE SoundLib::t0 = NULL;