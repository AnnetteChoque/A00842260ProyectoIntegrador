
#include <iostream>
#include <vector>
#include <fstream>
#include "clases.h"
using namespace std;

/**
    Vector global que almacena todos los videos cargados (películas y series)
 */
vector<Video*> videos;

/**
      Carga datos iniciales de prueba al vector 'videos'
 */
void CargarDatos() {
    // Películas
    Pelicula* p1 = new Pelicula("P001", "Inception", 148, "accion");
    p1->Calificar(4);
    p1->Calificar(5);
    videos.push_back(p1);

    Pelicula* p2 = new Pelicula("P002", "El Padrino", 175, "drama");
    p2->Calificar(5);
    p2->Calificar(5);
    p2->Calificar(4);
    videos.push_back(p2);

    Pelicula* p3 = new Pelicula("P003", "The Dark Knight", 152, "accion");
    p3->Calificar(5);
    p3->Calificar(4);
    videos.push_back(p3);

    Pelicula* p4 = new Pelicula("P004", "Forrest Gump", 142, "drama");
    p4->Calificar(4.5);
    p4->Calificar(5);
    videos.push_back(p4);

    Pelicula* p5 = new Pelicula("P005", "Interstellar", 169, "ciencia ficcion");
    p5->Calificar(5);
    p5->Calificar(4.8);
    videos.push_back(p5);

    Pelicula* p6 = new Pelicula("P006", "Titanic", 194, "drama");
    p6->Calificar(4.7);
    p6->Calificar(4.9);
    videos.push_back(p6);

    Pelicula* p7 = new Pelicula("P007", "Gladiator", 155, "accion");
    p7->Calificar(4.6);
    p7->Calificar(5);
    videos.push_back(p7);

    Pelicula* p8 = new Pelicula("P008", "Avengers Endgame", 181, "accion");
    p8->Calificar(5);
    p8->Calificar(5);
    videos.push_back(p8);

    // Series
    Serie* s1 = new Serie("S001", "Stranger Things", 50, "misterio");
    s1->AgregarEpisodio(Episodio("Capitulo Uno", 1, 4.5));
    s1->AgregarEpisodio(Episodio("Capitulo Dos", 1, 4.7));
    videos.push_back(s1);

    Serie* s2 = new Serie("S002", "The Mandalorian", 45, "accion");
    s2->AgregarEpisodio(Episodio("Una Nueva Esperanza", 1, 4.6));
    s2->AgregarEpisodio(Episodio("La Búsqueda", 2, 4.3));
    videos.push_back(s2);

    Serie* s3 = new Serie("S003", "Breaking Bad", 47, "drama");
    s3->AgregarEpisodio(Episodio("Piloto", 1, 4.8));
    s3->AgregarEpisodio(Episodio("Proceso Químico", 1, 4.7));
    videos.push_back(s3);

    Serie* s4 = new Serie("S004", "Friends", 22, "comedia");
    s4->AgregarEpisodio(Episodio("La Tormenta", 1, 4.5));
    s4->AgregarEpisodio(Episodio("La Mudanza", 2, 4.4));
    videos.push_back(s4);

    Serie* s5 = new Serie("S005", "The Office", 23, "comedia");
    s5->AgregarEpisodio(Episodio("La Entrevista", 1, 4.6));
    s5->AgregarEpisodio(Episodio("Fiesta de Oficina", 3, 4.5));
    videos.push_back(s5);

    Serie* s6 = new Serie("S006", "The Crown", 60, "drama");
    s6->AgregarEpisodio(Episodio("Coronacion", 1, 4.7));
    s6->AgregarEpisodio(Episodio("Escandalo Real", 2, 4.6));
    videos.push_back(s6);

    Serie* s7 = new Serie("S007", "La Casa de Papel", 50, "suspenso");
    s7->AgregarEpisodio(Episodio("Robo Historico", 1, 4.8));
    s7->AgregarEpisodio(Episodio("El Plan", 2, 4.9));
    videos.push_back(s7);

    Serie* s8 = new Serie("S008", "The Flash", 43, "accion");
    s8->AgregarEpisodio(Episodio("La Partida de Barry", 1, 4.6));
    s8->AgregarEpisodio(Episodio("Fuerza de la Naturaleza", 2, 4.5));
    s8->AgregarEpisodio(Episodio("El Hombre del Futuro", 3, 4.7));
    s8->AgregarEpisodio(Episodio("Vuelta a la Velocidad", 4, 4.8));
    videos.push_back(s8);
}

/**
     Muestra videos filtrados por calificación mínima o género
 */
void MostrarPorCalifGenero() {
    int op;
    cout << "1. Por calificacion\n2. Por genero\nOpcion: ";
    cin >> op;

    if (op == 1) {
        double calif;
        cout << "Calificacion minima: ";
        cin >> calif;

        for (auto vid : videos)
            if (vid->ObtenerCalPromedio() >= calif)
                vid->mostrarInfo();
    } else if (op == 2) {
        string genero;
        cin.ignore();
        cout << "Genero: ";
        getline(cin, genero);

        for (auto vid : videos)
            if (vid->GetGenero() == genero)
                vid->MostrarInfo();
    } else {
        cout << "Opcion invalida.\n";
    }
}

/**
       Muestra los episodios de una serie con calificación mayor o igual a un valor dado
 */
void MostrarEpsSerie() {
    string titulo;
    double calif;

    cin.ignore();
    cout << "Titulo de la serie: ";
    getline(cin, titulo);
    cout << "Calificacion minima del episodio: ";
    cin >> calif;

    for (auto vid : videos) {
        Serie* s = dynamic_cast<Serie*>(vid);
        if (s && s->GetTitulo() == titulo) {
            s->MostrarEpsCalificados(calif);
        }
    }
}

/**
     Muestra películas con calificación mínima
 */
void MostrarPelsPorCalif() {
    double calif;
    cout << "Calificacion minima: ";
    cin >> calif;

    for (auto vid : videos) {
        Pelicula* p = dynamic_cast<Pelicula*>(vid);
        if (p && p->ObtenerCalPromedio() >= calif)
            p->MostrarInfo();
    }
}

/**
     Permite calificar un video existente
 */
void calificarVideo() {
    cin.ignore();
    string titulo;
    int valor;

    cout << "Titulo del video: ";
    getline(cin, titulo);
    cout << "Valor (1-5): ";
    cin >> valor;

    bool encontrado = false;
    for (auto vid : videos) {
        if (vid->GetTitulo() == titulo) {
            vid->Calificar(valor);
            cout << "Calificacion agregada.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "Video no encontrado.\n";
}

/**
      Función principal del programa
       Código de salida
 */
int main() {
    int opcion;

    cout << "Cargando datos directamente desde el programa...\n";
    CargarDatos();

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Cargar archivo de datos\n";
        cout << "2. Mostrar videos por calificacion o genero\n";
        cout << "3. Mostrar episodios por serie y calificacion\n";
        cout << "4. Mostrar peliculas con cierta calificacion\n";
        cout << "5. Calificar un video\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Los datos ya fueron cargados al iniciar.\n";
                break;
            case 2:
                MostrarPorCalifGenero();
                break;
            case 3:
                MostrarEpsSerie();
                break;
            case 4:
                MostrarPelsPorCalif();
                break;
            case 5:
                CalificarVideo();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    // Liberar memoria
    for (auto v : videos) {
        delete v;
    }

    return 0;
}
