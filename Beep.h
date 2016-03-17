#ifndef BEEP_H
#define BEEP_H
#pragma once
#include "Windows.h"
#include <string>
#include "strsafe.h"
#include "stdio.h"
#include <iostream>

//
// usage example:
//	SoundLib::Instance()->play(SoundLib::AllStar);
//  WaitForSingleObject(SoundLib::t0, INFINITE);
class SoundLib
{
private: static float tempo;
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
        int l = (int)(tempo / inverseFractionOfQuarterNote);
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

	enum TrackName { SMBDie, SMBWin, NSMBBGM, SMDDie, SMDWin, Sonic1GHZ, ReconstructingMoreScience, YourPreciousMoon, MagicRoundabout, AllStar, Umaru, Futurama, PinkPanther, DarkKnightRises, Stop };

	static DWORD WINAPI musicSMBDie(LPVOID lpParam = 0) { float initTempo = tempo; tempo = 600.0f; slBeep(B3, 4); slBeep(F4, 2); slBeep(F4, 4); slBeep(F4, 3); slBeep(E4, 3); slBeep(D4, 3); slBeep(C4, 4); slBeep(E3, 2); slBeep(E3, 4); slBeep(C3, 2); tempo = initTempo; return 0; }
	
	static DWORD WINAPI musicSMBWin(LPVOID lpParam = 0) { float initTempo = tempo; tempo = 600.0f; slBeep(G2, 3); slBeep(C3, 3); slBeep(E3, 3); slBeep(G3, 3); slBeep(C4, 3); slBeep(E4, 3); slBeep(G4, 1); slBeep(E4, 1); slBeep(Gsharp2, 3); slBeep(C3, 3); slBeep(Dsharp3, 3); slBeep(Gsharp3, 3); slBeep(C4, 3); slBeep(Dsharp4, 3); slBeep(Gsharp4, 1); slBeep(Dsharp4, 1); slBeep(Asharp2, 3); slBeep(D3, 3); slBeep(F3, 3); slBeep(Asharp3, 3); slBeep(D4, 3); slBeep(F4, 3); slBeep(Asharp4, 1); slBeep(Asharp4, 3); slBeep(Asharp4, 3); slBeep(Asharp4, 3); slBeep(C5, 0.5f); tempo = initTempo; return 0; }
	static DWORD WINAPI musicNSMBBGM(LPVOID lpParam = 0)
        {
            while (true)
            {
                tempo = 300.0f;
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
	static DWORD WINAPI musicSMBDieBass(LPVOID lpParam = 0) { tempo = 600.0f; slBeep(G2, 2); slBeep(R, 4); slBeep(G2, 4); slBeep(G2, 3); slBeep(A2, 3); slBeep(B2, 3); slBeep(C3, 2); slBeep(G2, 2); slBeep(C2, 2); return 0; }

	static DWORD WINAPI musicSMDWin(LPVOID lpParam = 0) { float initTempo = tempo; tempo = 350.0f; slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3); slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3); slBeep(G3, 2); slBeep(G3, 2); slBeep(C4); slBeep(B3, 0.5f); slBeep(C5, 2); slBeep(B4, 2); slBeep(G4, 2); slBeep(A4, 0.2f); tempo = initTempo; return 0; }
	static DWORD WINAPI musicS1GHZ(LPVOID lpParam = 0)
	{
		float initTempo = tempo; tempo = 400.0f;
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
            float initTempo = tempo; tempo = 600.0f;
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
            tempo = initTempo;
			return 0;
        }
	static DWORD WINAPI musicPreciousMoon(LPVOID lpParam = 0)
        {
            float initTempo = tempo; tempo = 600.0f;
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
            tempo = initTempo;
			return 0;
        }

	static DWORD WINAPI musicMagicRnd(LPVOID lpParam = 0)
    {
        float initTempo = tempo; tempo = 500.0f;
        for (byte b0 = 0; b0 < 2; b0++)
        {
            slBeep(C5); slBeep(C5, 2); slBeep(C5, 2); slBeep(G4); slBeep(G4);
            slBeep(A4); slBeep(A4, 2); slBeep(A4, 2); slBeep(F4, 0.5f);
            slBeep(Asharp4); slBeep(Asharp4, 2); slBeep(Asharp4, 2); slBeep(F4); slBeep(F4);
            slBeep(B4); slBeep(B4, 2); slBeep(B4, 2); if (b0<1) slBeep(G4, 0.5f);
        }
        slBeep(G4); slBeep(G4); slBeep(C5, 0.2f);
        tempo = initTempo;
		return 0;
    }
	static DWORD WINAPI musicUMR(LPVOID lpParam = 0)
	{
		float initTempo = tempo; tempo = 600.0f;
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
		tempo = initTempo;
		return 0;
	}
	static DWORD WINAPI musicFut(LPVOID lpParam = 0)
	{
		float initTempo = tempo; tempo = 600.0f;
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
		tempo = initTempo;
		return 0;
	}
	static DWORD WINAPI musicPP(LPVOID lpParam = 0)
	{
		float initTempo = tempo; tempo = 660.0f;
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

	static DWORD WINAPI musicAllStar(LPVOID lpParam = 0)
        {
            float initTempo = tempo; tempo = 550.0f;
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

            tempo = initTempo;
			return 0;
        }

	static DWORD WINAPI musicDarkKnight(LPVOID lpParam = 0)
	{
		float initTempo = tempo; tempo = 400.0f;

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
		printPaval();
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
		
		//slBeep(R, 0.001f);

		tempo = initTempo;
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
		std::cout << "\xDC       \n       ";
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
		std::cout << "      \n       ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << "\xDC\xDF \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "       \n       \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << "\xDF\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 3);
		std::cout << "       \n     \xDC";
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
		std::cout << "\xDC     \n";
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
		std::cout << "\xDC  \n  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 3);
		std::cout << "\xDB     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " \n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 3);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "    \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16);
		std::cout << "     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 * 16 + 1);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "      \xDB\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8 * 16 + 7);
		std::cout << "\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "     \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16);
		std::cout << "     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDC      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "\xDC\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "\xDF     ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 3);
		std::cout << "      \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		std::cout << "       \n\xDB    ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 3);
		std::cout << "      \xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		std::cout << "      ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\n ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
		std::cout << "\xDC\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 3);
		std::cout << "\xDB     \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11 * 16 + 8);
		std::cout << "\xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		std::cout << "     \xDC\xDB\n";
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
		std::cout << "  \n  \xDF";
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
		std::cout << "\xDF   \n    ";
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
		std::cout << "    \n    \xDB\xDB\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB\xDB \xDB\xDC\xDB  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC   \n   \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "  \xDC\xDC\xDB\xDF\xDC\xDB\xDF\xDB\xDF  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "   \n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "   \xDB\xDB\xDF";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDB \xDF\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "   \n   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "  \xDC\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << "   ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB  \xDB \xDF ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "  \n  \xDC";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "  \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDF    \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB\xDB\xDC ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "  \n  \xDB\xDB";
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
		std::cout << "\xDB  \n  \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 8);
		std::cout << "      \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDC  ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "\xDC \n \xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDF\xDF\xDB\xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16 + 7);
		std::cout << "      \xDB";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7 * 16 + 8);
		std::cout << "\xDB\xDB\xDC\xDB ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 * 16);
		std::cout << " \n ";
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
	static void printPaval()
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

    void play(TrackName a)
        {
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
                default:
					TerminateThread(t0, 0);
                    break;
            }
        }
};
#endif

float SoundLib::tempo = 600.0f;
SoundLib* SoundLib::mInstance = NULL;
LPDWORD SoundLib::t = 0;
HANDLE SoundLib::t0 = NULL;