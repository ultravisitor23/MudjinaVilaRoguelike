#define _CRT_SECURE_NO_WARNINGS

#define ANSI_BLACK "\x1b[30m"
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_WHITE "\x1b[37m"
#define ANSI_RESETSTYLE "\x1b[m"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#pragma comment(lib,"winmm.lib")

void saveData(void* data, const char* filename, size_t size) {
	FILE* file = fopen(filename, "wb");
	if (file == NULL) {
		fprintf(stderr, "Error: Failed to open file for writing\n");
		return;
	}

	size_t written = fwrite(data, 1, size, file);
	if (written != size) {
		fprintf(stderr, "Error: Failed to write data to file\n");
	}

	fclose(file);
}

void loadData(const char* filename, void* data, int size) {
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("Error: could not open file %s\n", filename);
		return;
	}

	fread(data, size, 1, fp);
	fclose(fp);
}

void generateStory(int setting_index, int character_index, int goal_index, int twist_index, int solution_index, int relationship_index, int issue_index, int title_index)
{
	// Define some arrays of story elements
	char* settings[] = { "the huge mansion", "Mudjoazija", "Nikola Marijanov's Forehead", "Goofland" };
	char* characters[] = { "a dumb gypsy", "Masnokosi", "an immigrant jew", "a father of a dumb gypsy" };
	char* goals[] = { "to find a family toenail clipper", "to find and capture \"The Prisoner\"", "to discover their grave", "to find out why grapes grow on bushes only in this place" };
	char* twists[] = { "they had eyelash cancer", "the man was handicapped", "the tomb was guarded by Dacic and 8 muscly men", "this entire problem was a decoy for a larger scheme" };
	char* solutions[] = { "By enlisting the help of an autistic", "By piecing together clues from a crime scene", "By outsmarting a homeless drunk smelly stupid addict", "By realising that the real problem were the friends we made along the way" };
	char* relationships[] = { "a slave", "their adopted kid", "Jeffrey Epstein", "an FBI agent" };
	char* issues[] = { "struggles with cocaine addiction", "carries the burden of a past murder", "is haunted by Kika's ghost", "must confront their fear of midgets"};

	// Act 1: Setup
	switch (title_index)
	{
	case 0: printf("Title: %s - %s; Part %d\n\n", characters[character_index], settings[setting_index], goal_index + twist_index * 4 + solution_index * 16 + relationship_index * 64 + issue_index * 256 + 1); break;
	case 1: printf("Title: %s - %s; Part %d\n\n", characters[character_index], goals[goal_index], setting_index + twist_index * 4 + solution_index * 16 + relationship_index * 64 + issue_index * 256 + 1); break;
	case 2: printf("Title: %s - %s; Part %d\n\n", characters[character_index], twists[twist_index], goal_index + setting_index * 4 + solution_index * 16 + relationship_index * 64 + issue_index * 256 + 1); break;
	case 3: printf("Title: %s - %s; Part %d\n\n", characters[character_index], issues[issue_index], goal_index + twist_index * 4 + solution_index * 16 + relationship_index * 64 + setting_index * 256 + 1); break;
	default:
		break;
	}
	printf("Once upon a time, in %s, %s sets out %s. Along the way, %s meets %s.\n\n",
		settings[setting_index], characters[character_index], goals[goal_index], characters[character_index],
		relationships[relationship_index]);

	// Act 2: Confrontation
	printf("However, %s soon discovers that %s. %s also %s.\n\n",
		characters[character_index], twists[twist_index], characters[character_index], issues[issue_index], issues[issue_index]);

	// Act 3: Resolution
	printf("Undeterred, %s comes up with a plan to overcome the obstacle. %s they succeed %s. In the end, %s resolves their personal issues and their relationship with %s is stronger than ever.\n",
		characters[character_index], solutions[solution_index], goals[goal_index], characters[character_index], relationships[relationship_index]);

	return 0;
}

void printfile(char filename[], char missingtext[], char color[])
{
	FILE* fptr;

	char c;

	// Open file
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		printf(missingtext);
		return;
	}

	printf(color);

	// Read contents from file
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}

	printf(ANSI_RESETSTYLE);

	fclose(fptr);
}

void computerGameSystem(char gamename[], char roomname[])
{
	char path[256];
	strcpy(path, "MODCONTENT/VideoGames/");
	strcat(path, gamename);
	strcat(path, "/");
	strcat(path, roomname);
	strcat(path, "/text.txt");
	printfile(path, "Invalid Input. Closing app.", ANSI_RESETSTYLE);

	char str[256];
	scanf("%s", str);

	FILE* fptr;

	char c;

	char filename[256];
	strcpy(filename, "MODCONTENT/VideoGames/");
	strcat(filename, gamename);
	strcat(filename, "/");
	strcat(filename, roomname);
	strcat(filename, "/choice+");
	strcat(filename, str);
	strcat(filename, ".txt");

	// Open file
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		computerGameSystem(gamename, roomname);
	}

	// Read contents from file
	fgets(str, 256, fptr);

	if (strcmp(str, "%finish%") == 0)
	{
		return;
	}

	else
	{
		computerGameSystem(gamename, str);
	}

	fclose(fptr);
}

void dreamSeq(int depth)
{
	if (depth <= 0) { printf("Probudio si se.\n"); return; }

	char t_imagePaint[5] = {' ', '.', '!', 'O', '#'};
	char t_imagePixels[8][8];
	int t_imageColors[8][8];

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			t_imagePixels[x][y] = t_imagePaint[rand() % 5];
			t_imageColors[x][y] = rand() % 6;
		}
	}

	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 16; y++)
		{
			int acx = x;
			int acy = y;
			if (x >= 8) acx = 15 - x;
			if (y >= 8) acy = 15 - y;

			switch (t_imageColors[acx][acy])
			{
			case 0: printf(ANSI_RED); break;
			case 1: printf(ANSI_GREEN); break;
			case 2: printf(ANSI_YELLOW); break;
			case 3: printf(ANSI_BLUE); break;
			case 4: printf(ANSI_MAGENTA); break;
			case 5: printf(ANSI_CYAN); break;
			default: break;
			}

			printf("%c", t_imagePixels[acx][acy]);
		}

		printf("\n");
	}
	
	printf(ANSI_RESETSTYLE);
	char* t_actions[] = { "prosao si kroz vrata", "pogledao si kroz prozor", "razgovarao si s njim", "pritisnuo si okidac", "pozdravio si se s njim", "iskocio si kroz prozor", 
	"otvorio si vrata", "udario si ga", "pobegao si", "zagledao si se", "sastavio si to", "slomio si to", "skocio si", "udahnuo si", "pravio si se mrtav", "konzumirao si", 
	"odmorio si se" };
	printf("%s\n", t_actions[rand() % 17]);
	getchar();
	dreamSeq(depth - (rand() % 5 + 1));
	return;
}

int main(void)
{
	char name[128];

	char* traderItemNames[] = { "", "Keradar", "Mudjompas", "Protivotrov", "Svitac", "Kugla za Bilijar", "Konzerva", "Armorpierce Gun", "Bozja Zastita"};

	static int mudja, choice, hp = 10, gasPress[30000], bGasOn = 0, putokaz[30000], hrana[30000], smellLead[30000], lastBeenOn = 0, mudjinKer, mudjinKerAngerLevel = 0, ormani[30000],
		items[30000], bKeradar = 0, inventory[1000], lichen[30000], lichenActivated[30000], lichenForest, grapes[13], turn, cat, kugleZaBilijar = 0, beleKugle = 0,
		stoloviZaBilijar[30000], cuvarkugla[30000], cuvarkuglaPoolProficency[30000], zeljkoMitrovic, bZeljkoMitrovicAlive = 1, bWanted = 0, bGodsProtection, godsProtectionMaxHP,
		library, bookshelf[2][5][4][25][8], booksRead[2][5][4][25], znanje, mirrors[30000], reklameZaBiblioteku[30000], traderLocation, traderInventory[1000], traderPrices[1000],
		warehouses[50], maps[30000], poolProficency = 25, maxHP = 0, beds[30000], nocniStolovi[30000], umor = 0, kompSoba, bComputerPassword = 0;

	time_t t;
	srand((unsigned)time(&t));

	int gameVersion = 1;

#pragma region Worldgen

	//Worldgen
	mudja = rand() % 30000;
	mudjinKer = rand() % 30000;
	lichenForest = rand() % 30000;
	zeljkoMitrovic = rand() % 30000;
	library = rand() % 29999;
	kompSoba = rand() % 30000;

#pragma region Nagazni aktivatori otrovnog gasa

	//Worldgen:Nagazni aktivatori otrovnog gasa
	for (int i = 0; i < 30000; i++)
	{
		gasPress[i] = 0;
	}

	printf("\n\nPostvljanje nagaznih aktivatora otrovnog gasa\n");

	for (int i = 0; i < 3000; i++)
	{
		gasPress[rand() % 30000] = 1;

		if (i % 30 == 29)
		{
			printf(".");
		}
	}

#pragma endregion

#pragma region Putokazi

	//Worldgen:Putokazi
	for (int i = 0; i < 30000; i++)
	{
		putokaz[i] = 0;
	}

	printf("\n\nPostvljanje putokaza\n");

	for (int i = 0; i < 3000; i++)
	{
		putokaz[rand() % 30000] = 1;

		if (i % 30 == 29)
		{
			printf(".");
		}
	}

#pragma endregion

#pragma region Hrana

	//Worldgen:Hrana
	for (int i = 0; i < 30000; i++)
	{
		hrana[i] = 0;
	}

	printf("\n\nBacanje hrane\n");

	for (int i = 0; i < 6000; i++)
	{
		hrana[rand() % 30000] = rand() % 5 + 1;

		if (i % 60 == 59)
		{
			printf(".");
		}
	}

#pragma endregion

#pragma region Definisanje Mirisa

	//Worldgen:Definisanje Mirisa

	printf("\n\nDefinisanje mirisa\n");

	for (int i = 0; i < 30000; i++)
	{
		smellLead[i] = rand() % 30000;

		if (i % 300 == 299)
		{
			printf(".");
		}
	}
#pragma endregion

#pragma region Ormani

	//Worldgen:Ormani
	for (int i = 0; i < 30000; i++)
	{
		ormani[i] = 0;
	}

	printf("\n\nPostavljanje ormana na za njih logicno mesto\n");

	for (int i = 0; i < 3000; i++)
	{
		ormani[rand() % 30000] = 1;

		if (i % 30 == 29)
		{
			printf(".");
		}
	}
#pragma endregion

#pragma region Items

	//Worldgen:Items
	for (int i = 0; i < 30000; i++)
	{
		items[i] = 0;
	}

	printf("\n\nRazbacivanje raznih predmeta\n");

	for (int i = 0; i < 7500; i++)
	{
		items[rand() % 30000] = rand() % 8 + 1;

		if (i % 75 == 74)
		{
			printf(".");
		}
	}
#pragma endregion

#pragma region Vinova Loza

	//Worldgen:Vinova Loza
	for (int i = 0; i < 30000; i++)
	{
		lichen[i] = 0;
	}

	printf("\n\nRast grozdja\n");

	for (int i = 0; i < 13; i++)
	{
		grapes[i] = rand() % 10 - 20;

		if (i > 2)
		{
			printf("..........");
		}
	}

	for (int i = 0; i < 30000; i++)
	{
		lichenActivated[i] = 0;
	}

	printf("\n\nRast vinove loze\n");

	for (int i = 0; i < 1200; i++)
	{
		lichen[rand() % 30000] = 1;

		if (i % 12 == 11)
		{
			printf(".");
		}
	}
#pragma endregion

#pragma region Inventory

	//Worldgen:Items
	for (int i = 0; i < 1000; i++)
	{
		inventory[i] = 0;
	}
#pragma endregion

#pragma region Kugle za bilijar

	//Worldgen:Kugle za bilijar
	for (int i = 0; i < 30000; i++)
	{
		stoloviZaBilijar[i] = 0;
	}

	printf("\n\nPostavljanje stolova za bilijar\n");

	for (int i = 0; i < 1000; i++)
	{
		int randm = rand() % 30000;
		stoloviZaBilijar[randm] = rand() % 15 + 1;
		cuvarkugla[randm] = rand() % 2;

		if (i % 10 == 9)
		{
			printf(".");
		}
	}

#pragma endregion

#pragma region Mirrors

	//Worldgen:Mirrors
	for (int i = 0; i < 30000; i++)
	{
		mirrors[i] = 0;
	}

	printf("\n\nGlancanje ogledala\n");

	for (int i = 0; i < 1500; i++)
	{
		mirrors[rand() % 30000] = 1;

		if (i % 15 == 14)
		{
			printf(".");
		}
	}
#pragma endregion

#pragma region Library

	//Worldgen:Library

	printf("\n\nPisanje knjiga\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 25; l++)
				{
					for (int m = 0; m < 8; m++)
					{
						bookshelf[i][j][k][l][m] = rand() % 4;
						booksRead[i][k][k][l] = 0;
					}
					printf(".");
				}
				printf(" ");
			}
			printf("\n");
		}
		printf("\n\n");
	}

	for (int i = 0; i < 30000; i++)
	{
		reklameZaBiblioteku[i] = 0;
	}

	printf("\n\nPravljenje putokaza za biblioteku\n");

	for (int i = 0; i < 1000; i++)
	{
		reklameZaBiblioteku[rand() % 30000] = 1;
		if (i % 10 == 9)
		{
			printf(".");
		}
	}
#pragma endregion

#pragma region Maps

	//Worldgen:Maps
	for (int i = 0; i < 30000; i++)
	{
		maps[i] = 0;
	}

	printf("\n\nKacenje mapa\n");

	for (int i = 0; i < 2500; i++)
	{
		maps[rand() % 30000] = rand() % 6 + 1;

		if (i % 25 == 24)
		{
			printf(".");
		}
	}
#pragma endregion

#pragma region Warehouses

	//Worldgen:Warehouses

	printf("\n\nOrganzacija magacina\n");

	for (int i = 0; i < 50; i++)
	{
		warehouses[i] = rand() % 30000;

		printf("..");
	}
#pragma endregion

#pragma region Beds

	//Worldgen:Beds

	for (int i = 0; i < 30000; i++)
	{
		beds[i] = 0;
	}

	printf("\n\nNamestanje posteljine\n");

	for (int i = 0; i < 1000; i++)
	{
		int randm = rand() % 30000;
		beds[randm] = 1;

		if (rand() % 2)
		{
			nocniStolovi[randm] = 1;
		}

		if (i % 10 == 9)
		{
			printf(".");
		}

		printf("%d ", randm);
	}
#pragma endregion

#pragma endregion

#pragma region Main Menu

	printf("\n\n\n\n\n");
	printf("___  ___          _ _ _               _   _ _ _        ______                       _ _ _        \n");
	printf("|  \\/  |         | (_|_)             | | | (_) |       | ___ \\                     | (_) |       \n");
	printf("| .  . |_   _  __| |_ _ _ __   __ _  | | | |_| | __ _  | |_/ /___   __ _ _   _  ___| |_| | _____ \n");
	printf("| |\\/| | | | |/ _` | | | '_ \\ / _` | | | | | | |/ _` | |    // _ \\ / _` | | | |/ _ \\ | | |/ / _ \\ \n");
	printf("| |  | | |_| | (_| | | | | | | (_| | \\ \\_/ / | | (_| | | |\\ \\ (_) | (_| | |_| |  __/ | |   <  __/\n");
	printf("\\_|  |_/\\__,_|\\__,_| |_|_| |_|\\__,_|  \\___/|_|_|\\__,_| \\_| \\_\\___/ \\__, |\\__,_|\\___|_|_|_|\\_\\___|\n");
	printf("                  _/ |                                              __/ |                        \n");
	printf("                 |__/                                              |___/                         \n\n");

	printf("Mudjina Vila Roguelike v1.1\n\n\n");
	printf("Mudja te je kidnapovao jer si govorio razne uvrede protiv roma.\n");
	printf("Sada je tvoje vreme da PREZIVIS.\n");
	printf("Ali PAZI! U kuci te jure i Mudja i njegov Otac.\n\n");
	printf("Za listu komandi napisi -001.\n");

	printf("\n\nUnesi ime (max 128 slova, bez razmaka):");
	scanf("%s", name);

#pragma endregion

	//Igrica

	do {
		printf("\n>");
		scanf("%d", &choice);

		if (choice >= 0 && choice < 30000)
		{
			smellLead[lastBeenOn] = choice;
			lastBeenOn = choice;
			umor++;
			turn++;

			if (hp > maxHP)
			{
				maxHP = hp;
			}

			if (choice != mudja)
			{
				if (bGasOn)
					hp--;

				printf("\n----------------\n|%s|HP:%d|Umor:%d|Kugle za bilijar:%d; Bele:%d|Znanje:%d|Turn:%d|", name, hp, umor, kugleZaBilijar, beleKugle, znanje, turn);

				if (bKeradar)
				{
					printf("Lokacija psa:%d|", mudjinKer);
					if (rand() % 10 == 0)
					{
						bKeradar = 0;
					}
				}

				#pragma region Maèe AI
				if (choice != cat)
				{
					cat = rand() % 30000;
					while (!lichen[cat])
					{
						cat = rand() % 30000;
					}
				}
				if (inventory[2])
				{
					if (rand() % 25 == 0)
					{
						cat = choice;
					}
				}
				if (choice == cat)
				{
					if (abs(lichenForest - choice) <= 6)
					{
						printf("\n/!\\ Mudjino mace se igra sa svicima.");
					}
					else
					{
						printf("\n/!\\ Mudjino mace je protrcalo kroz ovu sobu.");
					}
				}
				#pragma endregion

				#pragma region Ker AI
				mudjinKer = smellLead[mudjinKer];
				if (mudjinKer == choice)
				{
					mudjinKerAngerLevel++;

					switch (mudjinKerAngerLevel)
					{
					case 1: printf("\n/!\\ Mudjin Ker se naljutio!"); break;
					case 2: printf("\n/!\\ Mudjin Ker se oblizuje!!"); break;
					case 3: printf("\n/!\\ Mudjin Ker skace na tebe!!!"); break;
					case 4: hp -= 4; printf("\n/!\\ Mudjin Ker te je ugrizao!!!!"); mudjinKerAngerLevel = 1; break;
					default: break;
					}
				}
				else
				{
					if (mudjinKerAngerLevel > 0)
					{
						mudjinKerAngerLevel--;
					}
				}
				if (abs(mudjinKer - choice) <= 500)
				{
					mudjinKer = choice;
				}
				else if (abs(mudjinKer - cat) <= 1500)
				{
					mudjinKer = cat;
				}
				#pragma endregion

				if (bZeljkoMitrovicAlive)
				#pragma region Željko Mitroviæ AI
				if (choice != zeljkoMitrovic)
				{
					zeljkoMitrovic = rand() % 30000;
					while (!stoloviZaBilijar[zeljkoMitrovic])
					{
						zeljkoMitrovic = rand() % 30000;
					}
				}
				if (choice == zeljkoMitrovic)
				{
					if (bWanted)
					{
						printf("\n/!\\ Masnokosi te napada rukom svog Mecha.");
						hp -= 20;
					}
					else
					{
						printf("\n<> U ovoj sobi Zeljko Mitrovic sedi u Mech robotu.");
					}

					printfile("RESOURCES/IMAGES/ZeljkoMitrovic.txt", "Slika RESOURCES/IMAGES/ZeljkoMitrovic.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_BLUE);
				}
				else if (abs(choice - zeljkoMitrovic) <= 5000)
				{
					if (bWanted)
					{
						printf("\n/!\\ Masnokosi te je upucao Kuglom za bilijar!");
						hp -= rand() % 6 + 10;
					}
				}
				else if (abs(mudjinKer - zeljkoMitrovic) <= 2500 && bWanted)
				{
					printf("\n<> Cuo si zvizdanje.");
					if ((zeljkoMitrovic > mudjinKer && zeljkoMitrovic > choice) || (zeljkoMitrovic < mudjinKer && zeljkoMitrovic < choice))
					{
						mudjinKer = choice;
					}
					else
					{
						mudjinKer = zeljkoMitrovic;
					}
				}
				#pragma endregion

				#pragma region Trader AI
				traderLocation = rand() % 30000;
				
				if (items[traderLocation])
				{
					traderInventory[items[traderLocation]]++;
					items[traderLocation] = 0;
				}
				
				if (turn % 10 == 0)
				{
					printf("\n/!\\ Naleteo si na prodavca.\n");

					for (int i = 0; i < 1000; i++)
					{
						if (traderInventory[i])
						{
							traderPrices[i] = rand() % 10 + 1;
							printf("| %d) %s x%d %dK ", i, traderItemNames[i], traderInventory[i], traderPrices[i]);
						}
					}

					printf("|\tNapisi -105 kako bi se trampio.");
				}
				#pragma endregion

				if (gasPress[choice])
				{
					printf("\n");

					if (!bGasOn)
						printf("/!\\ ");

					printf("STAO SI NA NAGAZNI AKTIVATOR! ");

					if (!bGasOn)
						printf("OTROVNI GAS JE ISPUNIO VILU.");

					bGasOn = 1;
				}

				if (putokaz[choice])
				{
					printf("\n");

					if (mudja > choice)
					{
						printf("<> Putokaz[>]: Mudja se nalazi na vecem broju.");
					}

					if (mudja < choice)
					{
						printf("<> Putokaz[<]: Mudja se nalazi na manjem broju.");
					}
				}

				if (hrana[choice])
				{
					printf("\n");
					hp += hrana[choice] * hrana[choice];

					if (hrana[choice] == 1)
					{
						printf("<> U ovoj sobi se nalazi Twix Choco Bar, pojeo si ga i vratio sebi 1HP.");
					}

					if (hrana[choice] == 2)
					{
						printf("<> U ovoj sobi se nalazi 100g Mini Panija sa belim sirom, pojeo si svih 100g i vratio sebi 4HP.");
					}

					if (hrana[choice] == 3)
					{
						printf("<> U ovoj sobi se nalazi");
						switch (rand() % 5)
						{
						case 0: printf(" Bubreg od mopsa! Pojeo si ga i vratio sebi 9HP."); break;
						case 1: printf(" Batak od mopsa! Pojeo si ga i vratio sebi 9HP."); break;
						case 2: printf(" Oko od mopsa! Pojeo si ga i vratio sebi 9HP."); break;
						case 3: printf(" Pasteta od mopsa! Pojeo si ga i vratio sebi 9HP."); break;
						case 4: printf(" Mozak od mopsa! Pojeo si ga i vratio sebi 9HP."); break;
						default: break;
						}
					}

					if (hrana[choice] == 4)
					{
						printf("<> U ovoj sobi se nalazi Hrenovka, pojeo si je i vratio sebi 16HP.");
					}

					if (hrana[choice] == 5)
					{
						printf("<> U ovoj sobi se nalazi Pecenje sa kajmakom, pojeo si ga i vratio sebi 25HP.");
					}

					hrana[choice] = 0;
				}

				if (ormani[choice])
				{
					printf("\n<> Orman: U ovoj sobi se nalazi orman. Napisi -101 da koristis orman.");
				}

				if (items[choice])
				{
					switch (items[choice])
					{
					case 1: printf("\n<> Radar za kera: Na podu se nalazi radar za Mudjinog psa. Uzeo si ga."); bKeradar = 1; break;
					case 2: printf("\n<> Kompas za Mudju (jednokratni): Na podu se nalazi Kompas za Mudju (jednokratni). Uzeo si ga. Napisi -201 da ga iskoristis."); inventory[1]++; break;
					case 3: printf("\n<> Protivotrov: Na podu se nalazi protivotrov za vrstu otrova koji trenutno ispunjava vilu. Mudja ce morati da nadje novi otrov ako zeli da te otruje! Uzeo si ga i popio."); bGasOn = 0; break;
					case 4: printf("\n<> Svitac: Mozes ga iskoristiti sa -202 na bilo kojoj sobi sa vinovom lozom da bi te odveo do sume vinove loze."); inventory[2]++; break;
					case 5: printf("\n<> Kugla za bilijar: Kada si usao u ovu sobu, okliznuo si se na kuglu za bilijar. Uzeo si je."); kugleZaBilijar++; break;
					case 6: printf("\n<> Konzerva: Mozes je otvoriti sa -203"); inventory[3]++; break;
					case 7: printf("\n  (                                 _");
							printf("\n   )                               /=>");
							printf("\n  (  +____________________/\\/\\___ / /|");
							printf("\n   .''._____________'._____      / /|/\\");
							printf("\n  : () :              :\\ ----\\|    \\ )");
							printf("\n   '..'______________.'0|----|      \\");
							printf("\n                    0_0/____/        \\");
							printf("\n                        |----    /----\\");
							printf("\n                       || -\\\\ --|      \\");
							printf("\n                       ||   || ||\\      \\");
							printf("\n                        \\\\____// '|      \\");
							printf("\n                                .'/       |");
							printf("\n                               .:/        |");
							printf("\n                               :/_________|\n");
							printf("\n<> Armorpierce Gun: Napisi -204 da ga iskoristis. Bice koristan u borbi protiv Zeljka Mitrovica. Sportski pozdrav!!"); inventory[4]++; break;
					case 8: printf("\n<> Bozja zastita: Ne gubis HP dok ne ispari!"); godsProtectionMaxHP = hp; bGodsProtection = 1; break;
					default:
						break;
					}

					items[choice] = 0;
				}

				if (lichen[choice])
				{
					printf("\n<> Vinova loza: Na zidovima raste vinova loza.");

					hp -= 5;

					if (!lichenActivated[choice])
					{
						int randm = rand() % 30000;
						printf("\n<*>Vinova loza je porasla do sobe %d.", randm);
						lichenActivated[choice] = 1;
						lichen[randm] = 1;
					}
				}

				if (abs(lichenForest - choice) == 6)
				{
					printf("\n<> Suma vinove loze: Suma vinove loze se ovde polako zavrsava.");
				}
				else if (abs(lichenForest - choice) <= 5)
				{
					printf("\n<> Suma vinove loze: Ovaj deo vile je pretvoren u sumu vinove loze.");
				}
				if (abs(lichenForest - choice) <= 6)
				{
					if (grapes[choice - lichenForest + 6] + 10 < turn)
					{
						printf("\n<> Na jednom zbunu u ovoj sumi se nalazi grozdje, napisi -102 da bi ga iskoristio.");
					}

					if (rand() % 10 == 0)
					{
						cat = choice;
						printf("\n/!\\ Mudjino mace je doslo u ovaj deo sume.");
					}
				}

				if (stoloviZaBilijar[choice])
				{
					printf("\n<> Sto za bilijar: U ovoj sobi se nalazi sto za bilijar na kom se nalazi %d kugala. Napisi -103 da ga iskoristis.", stoloviZaBilijar[choice]);
					if (cuvarkugla[choice])
					{
						printf("\n\tAli PAZI! U ovoj sobi se nalazi i cuvarkugla!");

						if (bWanted)
						{
							printf("\n\"Ealo! Nemoj da te puknem malo!\"\n\tTresnuo te je iz sve snage stapom za bilijar.");
							hp = rand() % hp;
							cuvarkugla[choice]++;

							if (cuvarkugla[choice] >= 6)
							{
								printf("\n\"E, sad je dosta. EALOOOOOO!!!\", gromovito se razdrao.");
								hp = rand() % hp;
							}
						}

						printfile("RESOURCES/IMAGES/Cuvarkugla.txt", "Slika RESOURCES/IMAGES/Cuvarkugla.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_RED);
					}
				}

				if (mirrors[choice])
				{
					printf("\n<> Ogledalo: Na zamrljanom ogledalu mozes videti svoj odraz:\n");
					char str[256];
					strcpy(str, "MODCONTENT/Characters/");
					strcat(str, name);
					strcat(str, ".txt");
					printfile(str, ".", ANSI_RESETSTYLE);
				}

				if (library == choice || library + 1 == choice)
				{
					printf("\n<> Biblioteka: Ovaj deo vile je pretvoren u biblioteku. Napisi -104 da bi interreagovao sa njom.");
				}

				if (reklameZaBiblioteku[choice])
				{
					printf("\n");

					if (library > choice)
					{
						printf("<> Reklama za biblioteku: ||Pozivamo Vas da posetite biblioteku %d>||", library - choice);
					}

					if (library < choice)
					{
						printf("<> Reklama za biblioteku: ||<%d Pozivamo Vas da posetite biblioteku||", choice - library);
					}
				}

				if (maps[choice])
				{
					switch (maps[choice])
					{
					case 1: printf("\n<> Na zidu se nalazi mapa Mudjoazije. Mozes videti Mudjinu vilu kako prekriva pola kontinenta."); break;
					case 2: printf("\n<> Na zidu se nalazi mapa Imapricije. Pored mape se nalazi portret jednog lepog maldica, a ispod te slike rec \"Simi\"."); break;
					case 3: printf("\n<> Na zidu se nalazi mapa Gooflanda. Sve je napisano u fontu Comic Sans."); break;
					case 4: printf("\n<> Na zidu se nalazi mapa Icefielda..."); break;
					case 5: printf("\n<> Na zidu se nalazi mapa Panceva. \n<> Soba mirise na azbest i amonijacnu kiselinu."); mudjinKer = rand() % 30000; break;
					case 6: printf("\n<> Na zidu se nalazi mapa Mudjine Vile. Pored mape je Mudjin portret."); break;
					default:
						break;
					}

					items[choice] = 0;
				}

				if (beds[choice])
				{
					printf("\n<> Krevet: U ovoj sobi se nalazi lepo namesten krevet. Napisi -106 da ga koristis.");

					if (nocniStolovi[choice])
					{
						printf("\n\tPored njega se nalazi nocni stocic.");
					}
				}

				if (abs(kompSoba - choice) <= 5)
				{
					printf("\n** Soba sa kompom: U blizini mozes cuti nesto sto zvuci kao mlazni avion i jos glasnije psovanje.");
				}
				if (kompSoba == choice)
				{
					printf("\n<> Kompjuter: Zvuci mlaznog aviona ti paraju usi, mada si sada i shvatio da te zvuke proizvodi napinjajuci kompjuter.\nIz jednog dela sobe zazidanog rigipsom moze se cuti covek kako psuje o tome kako nema nikoga u gejmu.\nNapisi -107 da bi ga iskoristio.");
				}

				//Gods Protection je uvek poslednja kalkulacija
				if (bGodsProtection)
				{
					hp = godsProtectionMaxHP;
					if (rand() % 2 == 0)
					{
						bGodsProtection = 0;
					}
				}
			}
		}

		else
		{
			if (choice == -001)
			{
				printf("\nTEHNICKE KOMANDE:\n");
				printf("-001\tLista komandi\n");
				printf("-002\tChangelog\n");
				printf("-003\tSave Game\n");
				printf("-004\tLoad Game\n");

				printf("\nKOMANDE ZA NEPOKRETNE OBJEKTE:\n");
				printf("-101\tKoristi orman\n");
				printf("-102\tKoristi grozdje\n");
				printf("-103\tKoristi sto za bilijar\n");
				printf("-104\tCitaj knjigu u biblioteci\n");
				printf("-105\tTrampi se sa prodavcem\n");
				printf("-106\tKoristi krevet\n");
				printf("-107\tKoristi komp\n");
				
				printf("\nKOMANDE ZA PREDMETE:\n");
				printf("-201\tKoristi Kompas za Mudju\n");
				printf("-202\tKoristi svica\n");
				printf("-203\tKoristi konzervu\n");
				printf("-204\tPucaj Armorpierce Guna\n");
			}

			if (choice == -002)
			{
				printf("\n\n-------CHANGELOG:-------\n\n");
				printf("18/10/22: Prva Verzija\n\tPrva verzija.\n\n");
				printf("18/10/22: Ker Update\n\tDodat pas i mirisi.\n\n");
				printf("19/10/22: The Lichen Forest Update\n\tDodati itemi: Mudjompas, Keradar, Protivotrov, Svitac\n\tDodata vinova loza, sume vinove loze, grozdje, macka.\n\tIgrica sada broji poteze.\n\n");
				printf("20/10/22 - 22/10/22: Civilisation Update\n\tDodate kugle za bilijar. Dodati stolovi za bilijar, cuvarkugle, Zeljko Mitrovic.\n\tDodati itemi: Kugla za bilijar, Konzerva, Armorpierce Gun, Bozija zastita.\n\tPromenjen redosled itema i namestaja (Funkcije za namestaj sada pocinju sa -1, a funkcije za iteme pocinju sa -2). Ovo je uradjeno zbog olaksavanja koriscenja i implementiranja buducih funkcija.\n\n");
				printf("29/10/22 - 22/02/23: Lore Update Part I -- Quality of Life Update:\n\tDodata biblioteka i police u njoj. Dodato znanje.\n\tLikovi sada imaju ime. Dodata ogledala!\n\tDodate mape.\n\tDodat prodavac i magacini. Itemi su sada cesci.\n\tIgrica sada moze da se sejva i louda. Igrica se sada arhivira posle svake verzije.\n\tOvo je tek prvi deo updatea.\n\n");
				printfile("RESOURCES/CHANGELOG/caleUpdate.txt", "Slika RESOURCES/CHANGELOG/caleUpdate.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_CYAN);
				printf("\n\n22/02/23 - 12/10/23: Cale Update:\n\tDodat Cale. Dodata soba sa kompom. Dodati kreveti i nocni stolovi. Dodat bilijar.\n\tDodati portreti nekih zivih bica i objekata\n\tNiz cuvarkuglaAngerLevel uklonjen -- njegova funkcija je sada integrisana u niz cuvarkugla. Kada cuvarkugla dostigne angerLevel od 6 ili vise (default 1), oduzece health igracu jos jednom, u istom maniru kao i prvi put.\n\tPopravljen Gods Protection. UI sa prodavcem je sada na srpskom. Pocetno vreme grozdja se sada pravilno generise. Sejvovi iz starijih verzija se sada azuriraju. Verzija igrice na glavnom meniju ce se od sad povecavati svakog updatea (trenutno v1.1).\n\tDok se generise svet, njegov progres se prikazuje i azurira. Help meni sada izgleda lepse.\n\n");
				/*printfile("RESOURCES/CHANGELOG/loreUpdate.txt", "Slika RESOURCES/CHANGELOG/loreUpdate.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_YELLOW);
				printfile("RESOURCES/CHANGELOG/parityUpdate.txt", "Slika RESOURCES/CHANGELOG/parityUpdate.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_WHITE);*/
			}

			if (choice == -003)
			{
				saveData(&gameVersion, "SAVE/.SAVE_VERSION.mvrl_savdat", sizeof(gameVersion));

				saveData(&name, "SAVE/name.mvrl_savdat", sizeof(name));
				saveData(&mudja, "SAVE/mudja.mvrl_savdat", sizeof(mudja));
				saveData(&choice, "SAVE/choice.mvrl_savdat", sizeof(choice));
				saveData(&hp, "SAVE/hp.mvrl_savdat", sizeof(hp));
				saveData(&gasPress, "SAVE/gasPress.mvrl_savdat", sizeof(gasPress));
				saveData(&bGasOn, "SAVE/bGasOn.mvrl_savdat", sizeof(bGasOn));
				saveData(&putokaz, "SAVE/putokaz.mvrl_savdat", sizeof(putokaz));
				saveData(&hrana, "SAVE/hrana.mvrl_savdat", sizeof(hrana));
				saveData(&smellLead, "SAVE/smellLead.mvrl_savdat", sizeof(smellLead));
				saveData(&lastBeenOn, "SAVE/lastBeenOn.mvrl_savdat", sizeof(lastBeenOn));
				saveData(&mudjinKer, "SAVE/mudjinKer.mvrl_savdat", sizeof(mudjinKer));
				saveData(&mudjinKerAngerLevel, "SAVE/mudjinKerAngerLevel.mvrl_savdat", sizeof(mudjinKerAngerLevel));
				saveData(&ormani, "SAVE/ormani.mvrl_savdat", sizeof(ormani));
				saveData(&items, "SAVE/items.mvrl_savdat", sizeof(items));
				saveData(&bKeradar, "SAVE/bKeradar.mvrl_savdat", sizeof(bKeradar));
				saveData(&inventory, "SAVE/inventory.mvrl_savdat", sizeof(inventory));
				saveData(&lichen, "SAVE/lichen.mvrl_savdat", sizeof(lichen));
				saveData(&lichenActivated, "SAVE/lichenActivated.mvrl_savdat", sizeof(lichenActivated));
				saveData(&lichenForest, "SAVE/lichenForest.mvrl_savdat", sizeof(lichenForest));
				saveData(&grapes, "SAVE/grapes.mvrl_savdat", sizeof(grapes));
				saveData(&turn, "SAVE/turn.mvrl_savdat", sizeof(turn));
				saveData(&cat, "SAVE/cat.mvrl_savdat", sizeof(cat));
				saveData(&kugleZaBilijar, "SAVE/kugleZaBilijar.mvrl_savdat", sizeof(kugleZaBilijar));
				saveData(&beleKugle, "SAVE/beleKugle.mvrl_savdat", sizeof(beleKugle));
				saveData(&stoloviZaBilijar, "SAVE/stoloviZaBilijar.mvrl_savdat", sizeof(stoloviZaBilijar));
				saveData(&cuvarkugla, "SAVE/cuvarkugla.mvrl_savdat", sizeof(cuvarkugla));
				saveData(&cuvarkuglaPoolProficency, "SAVE/cuvarkuglaPoolProficency.mvrl_savdat", sizeof(cuvarkuglaPoolProficency));
				saveData(&zeljkoMitrovic, "SAVE/zeljkoMitrovic.mvrl_savdat", sizeof(zeljkoMitrovic));
				saveData(&bZeljkoMitrovicAlive, "SAVE/bZeljkoMitrovicAlive.mvrl_savdat", sizeof(bZeljkoMitrovicAlive));
				saveData(&bWanted, "SAVE/bWanted.mvrl_savdat", sizeof(bWanted));
				saveData(&bGodsProtection, "SAVE/bGodsProtection.mvrl_savdat", sizeof(bGodsProtection));
				saveData(&godsProtectionMaxHP, "SAVE/godsProtectionMaxHP.mvrl_savdat", sizeof(godsProtectionMaxHP));
				saveData(&library, "SAVE/library.mvrl_savdat", sizeof(library));
				saveData(&bookshelf, "SAVE/bookshelf.mvrl_savdat", sizeof(bookshelf));
				saveData(&booksRead, "SAVE/booksRead.mvrl_savdat", sizeof(booksRead));
				saveData(&znanje, "SAVE/znanje.mvrl_savdat", sizeof(znanje));
				saveData(&mirrors, "SAVE/mirrors.mvrl_savdat", sizeof(mirrors));
				saveData(&reklameZaBiblioteku, "SAVE/reklameZaBiblioteku.mvrl_savdat", sizeof(reklameZaBiblioteku));
				saveData(&traderLocation, "SAVE/traderLocation.mvrl_savdat", sizeof(traderLocation));
				saveData(&traderInventory, "SAVE/traderInventory.mvrl_savdat", sizeof(traderInventory));
				saveData(&traderPrices, "SAVE/traderPrices.mvrl_savdat", sizeof(traderPrices));
				saveData(&warehouses, "SAVE/warehouses.mvrl_savdat", sizeof(warehouses));
				saveData(&maps, "SAVE/maps.mvrl_savdat", sizeof(maps));
				saveData(&poolProficency, "SAVE/poolProficency.mvrl_savdat", sizeof(poolProficency));
				saveData(&maxHP, "SAVE/maxHP.mvrl_savdat", sizeof(maxHP));
				saveData(&umor, "SAVE/umor.mvrl_savdat", sizeof(umor));
				saveData(&beds, "SAVE/beds.mvrl_savdat", sizeof(beds));
				saveData(&nocniStolovi, "SAVE/nocniStolovi.mvrl_savdat", sizeof(nocniStolovi));
				saveData(&kompSoba, "SAVE/kompSoba.mvrl_savdat", sizeof(kompSoba));
				saveData(&bComputerPassword, "SAVE/bComputerPassword.mvrl_savdat", sizeof(bComputerPassword));
			}

			if (choice == -004)
			{
				loadData("SAVE/name.mvrl_savdat", &name, sizeof(name));
				loadData("SAVE/mudja.mvrl_savdat", &mudja, sizeof(mudja));
				loadData("SAVE/choice.mvrl_savdat", &choice, sizeof(choice));
				loadData("SAVE/hp.mvrl_savdat", &hp, sizeof(hp));
				loadData("SAVE/gasPress.mvrl_savdat", gasPress, sizeof(gasPress));
				loadData("SAVE/bGasOn.mvrl_savdat", &bGasOn, sizeof(bGasOn));
				loadData("SAVE/putokaz.mvrl_savdat", putokaz, sizeof(putokaz));
				loadData("SAVE/hrana.mvrl_savdat", hrana, sizeof(hrana));
				loadData("SAVE/smellLead.mvrl_savdat", smellLead, sizeof(smellLead));
				loadData("SAVE/lastBeenOn.mvrl_savdat", &lastBeenOn, sizeof(lastBeenOn));
				loadData("SAVE/mudjinKer.mvrl_savdat", &mudjinKer, sizeof(mudjinKer));
				loadData("SAVE/mudjinKerAngerLevel.mvrl_savdat", &mudjinKerAngerLevel, sizeof(mudjinKerAngerLevel));
				loadData("SAVE/ormani.mvrl_savdat", ormani, sizeof(ormani));
				loadData("SAVE/items.mvrl_savdat", items, sizeof(items));
				loadData("SAVE/bKeradar.mvrl_savdat", &bKeradar, sizeof(bKeradar));
				loadData("SAVE/inventory.mvrl_savdat", inventory, sizeof(inventory));
				loadData("SAVE/lichen.mvrl_savdat", lichen, sizeof(lichen));
				loadData("SAVE/lichenActivated.mvrl_savdat", lichenActivated, sizeof(lichenActivated));
				loadData("SAVE/lichenForest.mvrl_savdat", &lichenForest, sizeof(lichenForest));
				loadData("SAVE/grapes.mvrl_savdat", grapes, sizeof(grapes));
				loadData("SAVE/turn.mvrl_savdat", &turn, sizeof(turn));
				loadData("SAVE/cat.mvrl_savdat", &cat, sizeof(cat));
				loadData("SAVE/kugleZaBilijar.mvrl_savdat", &kugleZaBilijar, sizeof(kugleZaBilijar));
				loadData("SAVE/beleKugle.mvrl_savdat", &beleKugle, sizeof(beleKugle));
				loadData("SAVE/stoloviZaBilijar.mvrl_savdat", stoloviZaBilijar, sizeof(stoloviZaBilijar));
				loadData("SAVE/cuvarkugla.mvrl_savdat", cuvarkugla, sizeof(cuvarkugla));
				loadData("SAVE/cuvarkuglaPoolProficency.mvrl_savdat", cuvarkuglaPoolProficency, sizeof(cuvarkuglaPoolProficency));
				loadData("SAVE/zeljkoMitrovic.mvrl_savdat", &zeljkoMitrovic, sizeof(zeljkoMitrovic));
				loadData("SAVE/bZeljkoMitrovicAlive.mvrl_savdat", &bZeljkoMitrovicAlive, sizeof(bZeljkoMitrovicAlive));
				loadData("SAVE/bWanted.mvrl_savdat", &bWanted, sizeof(bWanted));
				loadData("SAVE/bGodsProtection.mvrl_savdat", &bGodsProtection, sizeof(bGodsProtection));
				loadData("SAVE/godsProtectionMaxHP.mvrl_savdat", &godsProtectionMaxHP, sizeof(godsProtectionMaxHP));
				loadData("SAVE/library.mvrl_savdat", &library, sizeof(library));
				loadData("SAVE/bookshelf.mvrl_savdat", bookshelf, sizeof(bookshelf));
				loadData("SAVE/booksRead.mvrl_savdat", booksRead, sizeof(booksRead));
				loadData("SAVE/znanje.mvrl_savdat", &znanje, sizeof(znanje));
				loadData("SAVE/mirrors.mvrl_savdat", mirrors, sizeof(mirrors));
				loadData("SAVE/reklameZaBiblioteku.mvrl_savdat", reklameZaBiblioteku, sizeof(reklameZaBiblioteku));
				loadData("SAVE/traderLocation.mvrl_savdat", &traderLocation, sizeof(traderLocation));
				loadData("SAVE/traderInventory.mvrl_savdat", traderInventory, sizeof(traderInventory));
				loadData("SAVE/traderPrices.mvrl_savdat", traderPrices, sizeof(traderPrices));
				loadData("SAVE/warehouses.mvrl_savdat", warehouses, sizeof(warehouses));
				loadData("SAVE/maps.mvrl_savdat", maps, sizeof(maps));
				loadData("SAVE/poolProficency.mvrl_savdat", &poolProficency, sizeof(poolProficency));
				loadData("SAVE/maxHP.mvrl_savdat", &maxHP, sizeof(maxHP));
				loadData("SAVE/umor.mvrl_savdat", &umor, sizeof(umor));
				loadData("SAVE/beds.mvrl_savdat", beds, sizeof(beds));
				loadData("SAVE/nocniStolovi.mvrl_savdat", nocniStolovi, sizeof(nocniStolovi));
				loadData("SAVE/kompSoba.mvrl_savdat", &kompSoba, sizeof(kompSoba));
				loadData("SAVE/bComputerPassword.mvrl_savdat", &bComputerPassword, sizeof(bComputerPassword));

				gameVersion = 0;
				loadData("SAVE/.SAVE_VERSION.mvrl_savdat", &gameVersion, sizeof(gameVersion));
				
				if (gameVersion == 0)
				{
					static int tCuvarkuglaAngerLevel[30000];
					loadData("SAVE/cuvarkuglaAngerLevel.mvrl_savdat", tCuvarkuglaAngerLevel, sizeof(tCuvarkuglaAngerLevel));

					for (int i = 0; i < 30000; i++)
					{
						cuvarkugla[i] += tCuvarkuglaAngerLevel[i];
					}

					for (int i = 0; i < 30000; i++)
					{
						if (stoloviZaBilijar[i] && cuvarkugla[i])
						{
							cuvarkuglaPoolProficency[i] = rand() % 100 + 1;
						}
					}

					poolProficency = 50;

					for (int i = 0; i < 30000; i++)
					{
						beds[i] = 0;
					}

					for (int i = 0; i < 1000; i++)
					{
						int randm = rand() % 30000;
						beds[randm] = 1;

						if (rand() % 2)
						{
							nocniStolovi[randm] = 1;
						}

						if (i % 10 == 9)
						{
							printf(".");
						}
					}

					maxHP = 10;
					umor = turn;

					kompSoba = rand() % 30000;

					gameVersion = 1;
				}
			}

			if (choice == -201 && inventory[1] > 0)
			{
				printf("\nFUNKCIJE MUDJOMPASA:\n\n1: Pogledaj gde je Mudja.");
				printf("\n\n>");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1: 
					if (mudja > lastBeenOn)
					{
						printf("\n(>)");
					}

					if (mudja < lastBeenOn)
					{
						printf("\n(<)");
					} 
					inventory[1]--; break;
				default: break;
				}
			}

			if (choice == -202 && inventory[2] > 0)
			{
				printf("\nFUNKCIJE SVICA:\n\n1: Nahrani ga vinovom lozom.");
				printf("\n\n>");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1:
					if (lichen[lastBeenOn])
					{
						printf("\nSvitac te je odveo do sume vinove loze (br. %d).", lichenForest);
					}
					inventory[2]--; break;
				default: break;
				}
			}

			if (choice == -203 && inventory[3] > 0)
			{
				printf("\nKONZERVA:\n\n1: Otvori konzervu i pojedi sta god je unutra.");
				printf("\n\n>");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1:
					if (rand() % 2 == 0)
					{
						printf("\nPojeo si konzervirani gulaš od zmije. Vratio si sebi 30HPa.");
						hp += 30;
					}
					else
					{
						printf("\nPojeo si konzervirani gulaš od zmije. Bio je pokvaren! Izgubio si 10HPa i otrovao si se!");
						hp -= 10; bGasOn = 1;
					}
					inventory[3]--; break;
				default: break;
				}
			}

			if (choice == -204 && abs(choice - zeljkoMitrovic) <= 2500 && bZeljkoMitrovicAlive && kugleZaBilijar > 0 && inventory[4] > 0)
			{
				kugleZaBilijar--;

				if (rand() % 10 == 0)
				{
					printf("\nUpucao si Masnokosog pravo u celo! Pao je dole.");
					bZeljkoMitrovicAlive = 0;
					kugleZaBilijar = 10000;
				}
			}

			if (choice == -101 && ormani[lastBeenOn])
			{
				printf("\nORMANSKE FUNKCIJE:\n\n1: Sakrij se u ormance.");
				printf("\n\n>");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1: printf("\nSakrio si se u orman."); mudjinKer = rand() % 30000; break;
				default: break;
				}
			}

			if (choice == -102 && abs(lichenForest - lastBeenOn) <= 6 && grapes[lastBeenOn - lichenForest + 6] + 10 < turn)
			{
				printf("\nFUNKCIJE GROZDjA:\n\n1: Pojedi grozdje.");
				printf("\n\n>");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1: printf("\nPojeo si grozdje. Vratio si sebi 5HP."); hp += 5; grapes[lastBeenOn - lichenForest + 6] = turn; break;
				default: break;
				}
			}

			if (choice == -103 && stoloviZaBilijar[lastBeenOn])
			{
				printf("\nSTO ZA BILIJAR:\n\n1: Uzmi n kugala.\n2: Uzmi sve kugle.\n3: Igraj bilijar.");
				printf("\n\n>");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1: printf("\nKoliko kugala uzeti?"); scanf("%d", &choice); if (choice <= stoloviZaBilijar[lastBeenOn])
				{
					kugleZaBilijar += choice;
					printf("Uzeo si %d kugala sa stola.", choice);
				}; stoloviZaBilijar[lastBeenOn] -= choice; if (cuvarkugla[lastBeenOn])
				{
					bWanted = 1;
				}break;
				case 2: kugleZaBilijar += stoloviZaBilijar[lastBeenOn]; stoloviZaBilijar[lastBeenOn] = 0; printf("Uzeo si sve kugle sa stola."); if (cuvarkugla[lastBeenOn])
				{
					bWanted = 1;
				}break;
				case 3: if (cuvarkugla[lastBeenOn] && !cuvarkuglaPoolProficency[lastBeenOn])
				{
					int yourBalls = 0, enemyBalls = 0, enemyProficency;

					cuvarkuglaPoolProficency[lastBeenOn] = rand() % 100 + 1;
					enemyProficency = cuvarkuglaPoolProficency[lastBeenOn];

					printf("\nSve lopte su magicno otisle u rupe, a zatim bese automatski izbacene i postavljene. Protivnik ti je dao stap. Razbio je lopte.\n");

					while (!(yourBalls == 7 || enemyBalls == 7))
					{
						//Player Turn
						printf(".");
						PlaySound("RESOURCES/SOUNDS/poolBallHitFail.wav", NULL, SND_FILENAME | SND_ASYNC);
						Sleep(100);

						if (rand() % 100 < poolProficency)
						{
							printf("\nUbacio si loptu!\n");
							yourBalls++;
							PlaySound("RESOURCES/SOUNDS/poolBallHitHole.wav", NULL, SND_FILENAME | SND_ASYNC);
							Sleep(150);
							if (rand() % 100 < poolProficency)
							{
								printf("Kakav Mitrobilijar!\n");
								poolProficency += 1;
								PlaySound("RESOURCES/SOUNDS/poolBallHitLevelUp.wav", NULL, SND_FILENAME | SND_ASYNC);
								Sleep(500);
							}
						}

						//Enemy Turn
						printf(".");
						PlaySound("RESOURCES/SOUNDS/poolBallHitFail.wav", NULL, SND_FILENAME | SND_ASYNC);
						Sleep(100);

						if (rand() % 100 < enemyProficency)
						{
							printf("\nUbacio protivnik loptu!\n");
							enemyBalls++;
							PlaySound("RESOURCES/SOUNDS/poolBallHitHole.wav", NULL, SND_FILENAME | SND_ASYNC);
							Sleep(150);
							if (rand() % 100 < enemyProficency)
							{
								printf("Kakav Mitrobilijar!\n");
								enemyProficency += 1;
								PlaySound("RESOURCES/SOUNDS/poolBallHitLevelUp.wav", NULL, SND_FILENAME | SND_ASYNC);
								Sleep(500);
							}
						}
					}

					cuvarkuglaPoolProficency[lastBeenOn] = 0;

					printf("\n");
					printfile("RESOURCES/IMAGES/PoolTable.txt", "Slika RESOURCES/IMAGES/PoolTable.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_GREEN);
					
					int tHole, tEnemyHole, tbMitrobilijar = 0, tbEnemyMitrobilijar = 0, tEightBall = rand() % 6 + 1, tbPromasio = 0, tbEnemyPromasio = 0;

					while (yourBalls < 8 && enemyBalls < 8)
					{
						if (yourBalls == 7)
						{
							if (!tbMitrobilijar)
							{
								tHole = rand() % 6 + 1;
								printf("\nMoras ubaciti osmicu u rupu %d. Srecno care!\n", tHole);
								tbMitrobilijar = 1;
							}

							printf("\nLopta se nalazi blizu rupe %d.\nDo koje rupe zelis da odgurnes loptu? (Napisi 7 za pomoc)", tEightBall);

							int temp; 
							scanf("%d", &temp);

							if (temp >= 7)
							{
								printf("\nNajlakse je ubaciti u rupu blizu koje je kugla, takodje je veoma lako ubaciti loptu u naspramnu rupu.\nUbaciti je u rupu koja se nalazi u uglu pored je srednje tesko, a najteze je ubaciti kuglu u rupe 2 i 5.\n");
							}

							else
							{
								if (temp == tEightBall)
								{
									if (temp == tHole)
									{
										if (rand() % 100 < poolProficency)
										{
											yourBalls++;
											printf("\nKAKAV MITROBILIJAR!!! BRAVO POBEDNICKI CARE KRALJU!");
										}

										else
										{
											printf("\nPromasaj");
											tbPromasio = 2;
										}
									}

									if (temp != tHole)
									{
										if (rand() % 100 < poolProficency)
										{
											printf("\nPromasaj");
											tbPromasio = 1;
										}

										else
										{
											printf("\nBRAVO UBACIO SI U... pogresnu rupu... O ne... O ne ne ne!!!");
											yourBalls = 0;
										}
									}
								}

								else if (temp == 7 - tEightBall && rand() % 100 < 90)
								{
									if (temp == tHole)
									{
										if (rand() % 100 < poolProficency)
										{
											yourBalls++;
											printf("\nKAKAV MITROBILIJAR!!! BRAVO POBEDNICKI CARE KRALJU!");
										}

										else
										{
											printf("\nPromasaj");
											tbPromasio = 2;
										}
									}

									if (temp != tHole)
									{
										if (rand() % 100 < poolProficency)
										{
											printf("\nPromasaj");
											tbPromasio = 1;
										}

										else
										{
											printf("\nBRAVO UBACIO SI U... pogresnu rupu... O ne... O ne ne ne!!!");
											yourBalls = 0;
										}
									}
								}

								else if ((temp == 1 || temp == 3 || temp == 4 || temp == 6) && rand() % 100 < 75)
								{
									if (temp == tHole)
									{
										if (rand() % 100 < poolProficency)
										{
											yourBalls++;
											printf("\nKAKAV MITROBILIJAR!!! BRAVO POBEDNICKI CARE KRALJU!");
										}

										else
										{
											printf("\nPromasaj");
											tbPromasio = 2;
										}
									}

									if (temp != tHole)
									{
										if (rand() % 100 < poolProficency)
										{
											printf("\nPromasaj");
											tbPromasio = 1;
										}

										else
										{
											printf("\nBRAVO UBACIO SI U... pogresnu rupu... O ne... O ne ne ne!!!");
											yourBalls = 0;
										}
									}
								}

								else if ((temp == 2 || temp == 5) && rand() % 100 < 50)
								{
									if (temp == tHole)
									{
										if (rand() % 100 < poolProficency)
										{
											yourBalls++;
											printf("\nKAKAV MITROBILIJAR!!! BRAVO POBEDNICKI CARE KRALJU!");
										}

										else
										{
											printf("\nPromasaj");
											tbPromasio = 2;
										}
									}

									if (temp != tHole)
									{
										if (rand() % 100 < poolProficency)
										{
											printf("\nPromasaj");
											tbPromasio = 1;
										}

										else
										{
											printf("\nBRAVO UBACIO SI U... pogresnu rupu... O ne... O ne ne ne!!!");
											yourBalls = 0;
										}
									}
								}

								tEightBall = temp;

								if (tbPromasio)
								{
									for (int i = 0; i < tbPromasio * tbPromasio; i++)
									{
										if (rand() % 100 > poolProficency)
										{
											tEightBall = rand() % 6 + 1;
											printf("\nOde lopta do rupe %d.", tEightBall);

											if (tEightBall != tHole && rand() % 100 > poolProficency)
											{
												printf("\nBRAVO UBACIO SI U... pogresnu rupu... O ne... O ne ne ne!!!");
												yourBalls = 0;
											}
										}
									}

									tbPromasio = 0;
								}
							}
						}

						else
						{
							if (rand() % 100 < poolProficency)
							{
								printf("\nUbacio si loptu!\n");
								yourBalls++;
								PlaySound("RESOURCES/SOUNDS/poolBallHitHole.wav", NULL, SND_FILENAME | SND_ASYNC);
								Sleep(150);
								if (rand() % 100 < poolProficency)
								{
									printf("Kakav Mitrobilijar!\n");
									poolProficency += 1;
									PlaySound("RESOURCES/SOUNDS/poolBallHitLevelUp.wav", NULL, SND_FILENAME | SND_ASYNC);
									Sleep(500);
								}
							}
						}

						if (enemyBalls == 7)
						{
							if (!tbEnemyMitrobilijar)
							{
								tEnemyHole = rand() % 6 + 1;
								printf("\nMora majmun da ubaci u rupu %d.\n", tEnemyHole);
								tbEnemyMitrobilijar = 1;
							}

							int temp;

							if (tEightBall == tEnemyHole || tEightBall == 7 - tEnemyHole)
							{
								temp = tEightBall;
							}
							
							else
							{
								temp = 7 - tEightBall;
							}

							if (temp >= 7)
							{
								printf("\nNajlakse je ubaciti u rupu blizu koje je kugla, takodje je veoma lako ubaciti loptu u naspramnu rupu.\nUbaciti je u rupu koja se nalazi u uglu pored je srednje tesko, a najteze je ubaciti kuglu u rupe 2 i 5.\n");
							}

							else
							{
								if (temp == tEightBall)
								{
									if (temp == tEnemyHole)
									{
										if (rand() % 100 < enemyProficency)
										{
											enemyBalls++;
											printf("\nI... Protivnik je napravio Mitrobilijar... Izgubio si...");
										}

										else
										{
											printf("\nPromasio retard");
											tbEnemyPromasio = 2;
										}
									}

									if (temp != tEnemyHole)
									{
										if (rand() % 100 < enemyProficency)
										{
											printf("\nPromasio retard");
											tbEnemyPromasio = 1;
										}

										else
										{
											printf("\nHahaha, majmun retard debil ubacio u pogresnu rupu, lol!");
											enemyBalls = 0;
										}
									}
								}

								else if (temp == 7 - tEightBall && rand() % 100 < 90)
								{
									if (temp == tEnemyHole)
									{
										if (rand() % 100 < enemyProficency)
										{
											enemyBalls++;
											printf("\nI... Protivnik je napravio Mitrobilijar... Izgubio si...");
										}

										else
										{
											printf("\nPromasio retard");
											tbEnemyPromasio = 2;
										}
									}

									if (temp != tEnemyHole)
									{
										if (rand() % 100 < enemyProficency)
										{
											printf("\nPromasio retard");
											tbEnemyPromasio = 1;
										}

										else
										{
											printf("\nHahaha, majmun retard debil ubacio u pogresnu rupu, lol!");
											enemyBalls = 0;
										}
									}
								}

								else if ((temp == 1 || temp == 3 || temp == 4 || temp == 6) && rand() % 100 < 75)
								{
									if (temp == tEnemyHole)
									{
										if (rand() % 100 < enemyProficency)
										{
											enemyBalls++;
											printf("\nI... Protivnik je napravio Mitrobilijar... Izgubio si...");
										}

										else
										{
											printf("\nPromasio retard");
											tbEnemyPromasio = 2;
										}
									}

									if (temp != tEnemyHole)
									{
										if (rand() % 100 < enemyProficency)
										{
											printf("\nPromasio retard");
											tbEnemyPromasio = 1;
										}

										else
										{
											printf("\nHahaha, majmun retard debil ubacio u pogresnu rupu, lol!");
											enemyBalls = 0;
										}
									}
								}

								else if ((temp == 2 || temp == 5) && rand() % 100 < 50)
								{
									if (temp == tEnemyHole)
									{
										if (rand() % 100 < enemyProficency)
										{
											enemyBalls++;
											printf("\nI... Protivnik je napravio Mitrobilijar... Izgubio si...");
										}

										else
										{
											printf("\nPromasio retard");
											tbEnemyPromasio = 2;
										}
									}

									if (temp != tEnemyHole)
									{
										if (rand() % 100 < enemyProficency)
										{
											printf("\nPromasio retard");
											tbEnemyPromasio = 1;
										}

										else
										{
											printf("\nHahaha, majmun retard debil ubacio u pogresnu rupu, lol!");
											enemyBalls = 0;
										}
									}
								}

								tEightBall = temp;

								if (tbEnemyPromasio)
								{
									for (int i = 0; i < tbEnemyPromasio * tbEnemyPromasio; i++)
									{
										if (rand() % 100 > enemyProficency)
										{
											tEightBall = rand() % 6 + 1;
											printf("\nOde lopta do rupe %d.", tEightBall);

											if (tEightBall != tEnemyHole && rand() % 100 > enemyProficency)
											{
												printf("\nUbacio lik u pogresnu rupu...");
												enemyBalls = 0;
											}
										}
									}

									tbEnemyPromasio = 0;
								}
							}
						}

						else
						{
							if (rand() % 100 < enemyProficency)
							{
								printf("\nUbacio protivnik loptu!\n");
								enemyBalls++;
								PlaySound("RESOURCES/SOUNDS/poolBallHitHole.wav", NULL, SND_FILENAME | SND_ASYNC);
								Sleep(150);
								if (rand() % 100 < enemyProficency)
								{
									printf("Kakav Mitrobilijar!\n");
									enemyProficency += 1;
									PlaySound("RESOURCES/SOUNDS/poolBallHitLevelUp.wav", NULL, SND_FILENAME | SND_ASYNC);
									Sleep(500);
								}
							}
						}
					}

					if (yourBalls >= 8)
					{
						beleKugle++;
					}
				}
				else if (cuvarkuglaPoolProficency[lastBeenOn])
				{
					printf("\nVec si igrao bilijar ovde.");
				}
				else
				{
					printf("\nNe mozes igrati bilijar sam.");
				}break;
				default: break;
				}
			}

			if (choice == -104 && (library == lastBeenOn || library + 1 == lastBeenOn))
			{
				int polica, red, knjiga;

				printf("\nIZABERI POLICU (1-5):\n");
				printf("\n\n>");
				scanf("%d", &polica);
				printf("\nIZABERI RED (1-4):\n");
				printf("\n\n>");
				scanf("%d", &red);
				printf("\nIZABERI KNjIGU (1-25):\n");
				printf("\n\n>");
				scanf("%d", &knjiga);

				generateStory(bookshelf[lastBeenOn-library][polica - 1][red - 1][knjiga - 1][0], 
					bookshelf[lastBeenOn - library][polica - 1][red - 1][knjiga - 1][1], 
					bookshelf[lastBeenOn - library][polica - 1][red - 1][knjiga - 1][2], 
					bookshelf[lastBeenOn - library][polica - 1][red - 1][knjiga - 1][3], 
					bookshelf[lastBeenOn - library][polica - 1][red - 1][knjiga - 1][4], 
					bookshelf[lastBeenOn - library][polica - 1][red - 1][knjiga - 1][5], 
					bookshelf[lastBeenOn - library][polica - 1][red - 1][knjiga - 1][6],
					bookshelf[lastBeenOn - library][polica - 1][red - 1][knjiga - 1][7]);
				
				if (booksRead[lastBeenOn - library][polica - 1][red - 1][knjiga - 1] == 0)
				{
					znanje += rand() % 2 + 1;
					booksRead[lastBeenOn - library][polica - 1][red - 1][knjiga - 1] = 1;
				}
			}

			if (choice == -105 && turn % 10 == 0)
			{
				printf("\nID PREDMETA KOJI ZELIS DA KUPIS?\n");
				printf("\n\n>");
				scanf("%d", &choice);

				if (traderInventory[choice] > 0 && traderPrices[choice] <= kugleZaBilijar)
				{
					int tempPlaced = warehouses[rand() % 50];
					items[tempPlaced] = choice;
					traderInventory[choice]--;
					printf("\nProdavac ti je saopstio da se taj predmet nalazi u magacinu broj %d.", tempPlaced);
				}
			}

			if (choice == -106 && beds[lastBeenOn])
			{
				printf("\nFUNKCIJE KREVETA:\n\n1: Spavaj.");
				printf("\n\n>");
				scanf("%d", &choice);

				switch (choice)
				{
				case 1: printf("\n"); getchar(); dreamSeq(maxHP - hp); if (maxHP - hp < umor) { umor -= maxHP - hp; hp = maxHP; }
					  else { hp += umor; umor = 0; } break;
				default: break;
				}
			}

			if (choice == -107 && lastBeenOn == kompSoba)
			{
				if (!bComputerPassword)
				{
					int tYourCarPosition = 0, tYourCarHP = 100, tEnemyCarPosition = 0, tEnemyCarHP = 100, tGTARaceMap[32], tLandmines[32],
						tYourGrenades = 0, tYourLandmines = 0, tEnemyGrenades = 0, tEnemyLandmines = 0;

					for (int i = 0; i < 32; i++)
					{
						tGTARaceMap[i] = rand() % 5;
						tLandmines[i] = 0;
					}

					while (tYourCarPosition < 32 && tEnemyCarPosition < 32)
					{
						//Tvoj potez

						if (tGTARaceMap[tYourCarPosition] == 0)
						{
							printfile("RESOURCES/IMAGES/GTARace1.txt", "Slika RESOURCES/IMAGES/GTARace1.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_RESETSTYLE);
						
							if (rand() % 2)
							{
								printf("\nSkupio si granatu!\n");
								tYourGrenades++;
							}

							else
							{
								printf("\nSkupio si nagaznu minu!\n");
								tYourLandmines++;
							}

							tYourCarPosition += rand() % 4 + 1;

							Sleep(100);
						}

						if (tGTARaceMap[tYourCarPosition] == 1)
						{
							printfile("RESOURCES/IMAGES/GTARace2.txt", "Slika RESOURCES/IMAGES/GTARace2.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_RESETSTYLE);

							if (rand() % 2)
							{
								printf("\nZaobisao si prepreku!\n");
								tYourCarPosition += rand() % 4 + 1;
							}

							else
							{
								printf("\nSkucao si se!\n");
								tYourCarPosition ++;
							}

							Sleep(100);
						}

						if (tGTARaceMap[tYourCarPosition] == 2)
						{
							printfile("RESOURCES/IMAGES/GTARace3.txt", "Slika RESOURCES/IMAGES/GTARace3.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_RESETSTYLE);

							if (rand() % 2)
							{
								printf("\nUradio si ceo krug oko petlje!\n");
								tYourCarPosition += rand() % 4 + 1;
							}

							else
							{
								printf("\nPao si na krov sa vrha petlje!\n");
								tYourCarPosition++;
								tYourCarHP -= rand() % 5 + 11;
							}

							Sleep(100);
						}

						if (tGTARaceMap[tYourCarPosition] == 3)
						{
							printfile("RESOURCES/IMAGES/GTARace4.txt", "Slika RESOURCES/IMAGES/GTARace4.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_RESETSTYLE);

							if (rand() % 2)
							{
								printf("\nPreskocio si rampom na donji nivo!\n");
								tYourCarPosition += rand() % 4 + 1;
							}

							else
							{
								printf("\nPao si u provaliju...\n");
								tYourCarHP = 0;
							}

							Sleep(100);
						}

						if (tGTARaceMap[tYourCarPosition] == 4)
						{
							printfile("RESOURCES/IMAGES/GTARace5.txt", "Slika RESOURCES/IMAGES/GTARace5.txt nije nadjena! Ova slika dolazi u paketu sa igricom, pokusajte da je reinstalirate!", ANSI_RESETSTYLE);

							if (rand() % 2)
							{
								printf("\nOstro si skrenuo!\n");
								tYourCarPosition += rand() % 4 + 1;
							}

							else
							{
								printf("\nSkuconga\n");
								tYourCarPosition -= rand() % 4 + 1;
							}
							
							Sleep(100);
						}

						if (tLandmines[tYourCarPosition])
						{
							printf("\nStao si na nagaznu minu! Eksplodirao ti je automobil!\n");
							tYourCarHP = 0;
							tLandmines[tYourCarPosition] = 0;

							Sleep(100);
						}

						if (tYourCarHP <= 0)
						{
							printf("\nE... Cvrc...\n");
							tYourCarHP = 100;
							tYourCarPosition = floor(tYourCarPosition / 4.0) * 4;

							Sleep(500);
						}

						if (tYourCarPosition < 0)
						{
							tYourCarPosition = 0;
						}

						printf("\nHP: %d|Position: %d|Granate: %d|Mine: %d|", tYourCarHP, tYourCarPosition, tYourGrenades, tYourLandmines);
						if (tEnemyCarPosition - tYourCarPosition < -1)
						{
							printf("Cale je negde daleko iza tebe.\n");
						}
						if (tEnemyCarPosition - tYourCarPosition == -1)
						{
							printf("Cale je tik iza tebe.\n");
						}
						if (tEnemyCarPosition - tYourCarPosition == 0)
						{
							printf("Cale je odmah pored tebe.\n");
						}
						if (tEnemyCarPosition - tYourCarPosition == 1)
						{
							printf("Cale je tik ispred tebe.\n");
						}
						if (tEnemyCarPosition - tYourCarPosition > 1)
						{
							printf("Cale je daleko ispred tebe.\n");
						}

						printf("\nDa li ces: 0) Skipovati; 1) Baciti Granatu; 2) Postaviti Minu\n");
						int tempval;
						scanf("%d", &tempval);

						if (tempval == 1 && tYourGrenades)
						{
							if (-1 <= tEnemyCarPosition - tYourCarPosition <= 1)
							{
								printf("\nBonba puce!\n");
								tEnemyCarHP -= rand() % 25 + 1;
							}
							else
							{
								printf("\nPa de bacas bre kad nema nikog\n");
							}

							tYourGrenades--;
						}
						if (tempval == 2 && tYourLandmines)
						{
							tLandmines[tYourCarPosition] = 1;
							tYourLandmines--;
						}

						//CaletovPotez

						if (tGTARaceMap[tEnemyCarPosition] == 0)
						{
							if (rand() % 2)
							{
								printf("\nCale: \"E Cefane sad da vidis sta sam uzo ne bi verovo\"\n");
								tEnemyGrenades++;
							}

							else
							{
								printf("\nCale: \"E Cefane sad da vidis sta sam uzo ne bi verovo\"\n");
								tEnemyLandmines++;
							}

							tEnemyCarPosition += rand() % 4 + 1;

							Sleep(100);
						}

						if (tGTARaceMap[tEnemyCarPosition] == 1)
						{
							if (rand() % 2)
							{
								tEnemyCarPosition += rand() % 4 + 1;
							}

							else
							{
								printf("\nCale: \"Te izem ti bre ovu prepreku i ko je izmisli bre i celo pokolenje ti izem da ti izem!\"\n");
								tEnemyCarPosition++;
							}

							Sleep(100);
						}

						if (tGTARaceMap[tEnemyCarPosition] == 2)
						{
							if (rand() % 2)
							{
								printf("\nCale: \"Tri siksti master aj em tri siksti master\"\n");
								tEnemyCarPosition += rand() % 4 + 1;
							}

							else
							{
								printf("\nCale: \"Sacu bre da iscepam ovaj sto pa cu da idem kupujem novi\"\n");
								tEnemyCarPosition++;
								tEnemyCarHP -= rand() % 5 + 11;
							}

							Sleep(100);
						}

						if (tGTARaceMap[tEnemyCarPosition] == 3)
						{
							if (rand() % 2)
							{
								tEnemyCarPosition += rand() % 4 + 1;
							}

							else
							{
								printf("\nCale: \"Da Bog da izginu svi ovi ljudi dole bre, j**** ti stazu\"\n");
								tEnemyCarHP = 0;
							}

							Sleep(100);
						}

						if (tGTARaceMap[tEnemyCarPosition] == 4)
						{
							if (rand() % 2)
							{
								printf("\nCale: \"Kaki sam ja majstor e\"\n");
								tEnemyCarPosition += rand() % 4 + 1;
							}

							else
							{
								printf("\nCale: \"Jel ima bre normalna neka mapa za ovu igricu bre\"\n");
								tEnemyCarPosition -= rand() % 4 + 1;
							}

							Sleep(100);
						}

						if (tLandmines[tEnemyCarPosition])
						{
							printf("\nMogao si cuti kako Caletov auto leti u vazduh, a odmah zatim i zvukove lomljenja stola.\n");
							tEnemyCarHP = 0;
							tLandmines[tEnemyCarPosition] = 0;

							Sleep(100);
						}

						if (tEnemyCarHP <= 0)
						{
							printf("\nCale: \"A BRE JEL MOGUCE BRE SINE CEFANE SACU DA TI IZEM SVE ZIVO I MRTVO\"\n");
							Sleep(100);
							printf("\nCale slama tastaturu glavom.\n");
							Sleep(400);
							tEnemyCarHP = 100;
							tEnemyCarPosition = floor(tEnemyCarPosition / 4.0) * 4;
						}

						if (tEnemyCarPosition < 0)
						{
							tEnemyCarPosition = 0;
						}
						
						if (-1 <= tYourCarPosition - tEnemyCarPosition <= 1)
						{
							tempval = 1;
						}

						if (tYourCarPosition - tEnemyCarPosition < -1)
						{
							tempval = 2;
						}

						if (tempval == 1 && tEnemyGrenades)
						{
							printf("\nAuto odleteo u vazduh.\n");
							tYourCarHP -= rand() % 25 + 1;

							tEnemyGrenades--;
						}
						if (tempval == 2 && tEnemyLandmines)
						{
							tLandmines[tEnemyCarPosition] = 1;
							tEnemyLandmines--;
						}
					}

					if (tYourCarPosition >= 32)
					{
						printf("\n===You Win===\nCale ti je dao sifru za komp.");
						bComputerPassword = 1;
					}

					else
					{
						printf("\n===You Lose===\nVrati se ovde malo kasnije i probaj ponovo.");
					}
				}
				else
				{
					char tString[256];

					printf("\nUnesi ime programa: ");
					scanf("%s", tString);

					computerGameSystem(tString, "START");
				}
			}
		}

	} while (hp > 0 && choice != mudja);

	if (choice == mudja)
	{
		printf("\nStigao si u Plandiste... Sutra te ceka putovanje u Kragujevac...");
	}
	else
	{
		printf("\n                                 _____  _____\n");
		printf("                                <     `/     |\n");
		printf("                                 >          (\n");
		printf("                                |   _     _  |\n");
		printf("                                |  |_) | |_) |\n");
		printf("                                |  | \\ | |   |\n");
		printf("                                |            |\n");
		printf("                 ______.______M_|            |__________  _____\n");
		printf("               _/                                       \\|     |\n");
		printf("              |               R I P  I N  P E A C E            <\n");
		printf("              |_____.-._________              ____/|___________|\n");
		printf("                                | * 01/01/01 |\n");
		printf("                                | + 03/06/96 |\n");
		printf("                                |            |\n");
		printf("                                |            |\n");
		printf("                                |   _        <\n");
		printf("                                |__/         |\n");
		printf("                                 / `--.      |\n");
		printf("                               M|            |M\n");
		printf("                           |/.MM|          -< @MMM\n");
		printf("                           `\\M`@|     v      |@@M@MM\n");
		printf("                         .MMM@@@|M    |    M @@@MM@MMMM\n");
		printf("                    _.MMMMMM@@@@@@MM_/M\\_M@@MM@@@@@@@MMMMMM\n");
		printf("\n\n\n");
		printf("Mudja se nalazio na broju %d.", mudja);
	}
}

/*
UPDATE PLAN:
Ker Update
The Lichen Forest Update
Civilisation Update
Lore Update Part I
Cale Update
Lore Update Part IS (Parity Update)
Room Update
Lore Update Part II (Quarters Update)
Combat Update
Lore Update Part III (Final Update)
*/