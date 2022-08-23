#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music {
    char title[30];
    char artist[30];
    char album[30];
};

void newMusic(struct Music* playlistTotal, int* flagPointer);
void removeMusic(struct Music* playlist, int* flagPointer);
void printPlaylist(struct Music* playlist, int* totalMusics);
void resizePlaylist(struct Music** playlist, int* playlistSize);

int main() {
    int playlistSize = 2, counter = 0, *flagPointer = &counter;
    struct Music* playlist;

    playlist = calloc(playlistSize, sizeof(struct Music));

    strcpy(playlist[0].title, "Toma Toma na Pepeca");
    strcpy(playlist[0].artist, "Mc Junio");
    strcpy(playlist[0].album, "Calvo Tapes");

    strcpy(playlist[1].title, "Faroeste Caboclo");
    strcpy(playlist[1].artist, "Legião Urbana");
    strcpy(playlist[1].album, "Mais do Mesmo");
    counter += 2;
    if (playlistSize == counter) {
        resizePlaylist(&playlist, &playlistSize);
    }
    printPlaylist(playlist, flagPointer);
    newMusic(playlist, flagPointer);

    removeMusic(playlist, flagPointer);
    printPlaylist(playlist, flagPointer);

    return 0;
}

void newMusic(struct Music* playlist, int* flagPointer) {
    int opt = -1;
    struct Music music;

    printf("Digite o nome da música: ");
    fgets(music.title, 30, stdin);
    music.title[strcspn(music.title, "\n")] = 0;

    printf("Digite o nome do artista: ");
    fgets(music.artist, 30, stdin);
    music.artist[strcspn(music.artist, "\n")] = 0;

    printf("Digite o nome do album: ");
    fgets(music.album, 30, stdin);
    music.album[strcspn(music.album, "\n")] = 0;

    scanf("%i", &opt);

    switch (opt) {
        case 1: {
            for (int i = *flagPointer; i > 0; i--) {
                playlist[i] = playlist[i - 1];
            }
            playlist[0] = music;
            break;
        }
        case 2: {
            int n;
            scanf("%i", &n);
            for (int i = *flagPointer; i > n; i--) {
                playlist[i] = playlist[i - 1];
            }
            playlist[n] = music;
            break;
        }
        case 3: {
            playlist[*flagPointer] = music;
            break;
        }
        default: {
            printf("Opção inválida.\n");
            break;
        }
    }

    *flagPointer += 1;
}

void addMusicInBeginning(struct Music newMusic, struct Music* playlist) {}

void removeMusic(struct Music* playlist, int* flagPointer) {
    int opt = -1;
    struct Music music;

    strcpy(music.title, "");
    strcpy(music.artist, "");
    strcpy(music.album, "");

    scanf("%i", &opt);

    switch (opt) {
        case 1: {
            for (int i = 0; i < *flagPointer; i++) {
                playlist[i] = playlist[i + 1];
            }
            break;
        }
        case 2: {
            int n;
            scanf("%i", &n);
            for (int i = n; i < *flagPointer; i++) {
                playlist[i] = playlist[i + 1];
            }
            break;
        }
        case 3: {
            playlist[*flagPointer] = music;
            break;
        }
        default: {
            printf("Opção inválida.\n");
            break;
        }
    }

    *flagPointer -= 1;
}

void printPlaylist(struct Music* playlist, int* flagPointer) {
    for (int i = 0; i < *flagPointer; i++) {
        printf("Música: %s | Artista: %s | Álbum: %s\n", playlist[i].title, playlist[i].artist, playlist[i].album);
    }
}

void resizePlaylist(struct Music** playlist, int* playlistSize) {
    struct Music* newPlaylist;
    struct Music* tmpPlaylist;
    newPlaylist = calloc(*playlistSize * 2, sizeof(struct Music));

    for (int i = 0; i < *playlistSize; i++) {
        newPlaylist[i] = (*playlist)[i];
    }
    tmpPlaylist = *playlist;
    free(tmpPlaylist);
    *playlist = newPlaylist;
    *playlistSize *= 2;
}