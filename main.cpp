
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
void cargarDatos() {
    // Películas
    Pelicula* p1 = new Pelicula("P001", "Inception", 148, "accion");
    p1->calificar(4);
    p1->calificar(5);
    videos.push_back(p1);

    Pelicula* p2 = new Pelicula("P002", "El Padrino", 175, "drama");
    p2->calificar(5);
    p2->calificar(5);
    p2->calificar(4);
    videos.push_back(p2);

    Pelicula* p3 = new Pelicula("P003", "The Dark Knight", 152, "accion");
    p3->calificar(5);
    p3->calificar(4);
    videos.push_back(p3);

    Pelicula* p4 = new Pelicula("P004", "Forrest Gump", 142, "drama");
    p4->calificar(4.5);
    p4->calificar(5);
    videos.push_back(p4);

    Pelicula* p5 = new Pelicula("P005", "Interstellar", 169, "ciencia ficcion");
    p5->calificar(5);
    p5->calificar(4.8);
    videos.push_back(p5);

    Pelicula* p6 = new Pelicula("P006", "Titanic", 194, "drama");
    p6->calificar(4.7);
    p6->calificar(4.9);
    videos.push_back(p6);

    Pelicula* p7 = new Pelicula("P007", "Gladiator", 155, "accion");
    p7->calificar(4.6);
    p7->calificar(5);
    videos.push_back(p7);

    Pelicula* p8 = new Pelicula("P008", "Avengers Endgame", 181, "accion");
    p8->calificar(5);
    p8->calificar(5);
    videos.push_back(p8);

    // Series
    Serie* s1 = new Serie("S001", "Stranger Things", 50, "misterio");
    s1->agregarEpisodio(Episodio("Capitulo Uno", 1, 4.5));
    s1->agregarEpisodio(Episodio("Capitulo Dos", 1, 4.7));
    videos.push_back(s1);

    Serie* s2 = new Serie("S002", "The Mandalorian", 45, "accion");
    s2->agregarEpisodio(Episodio("Una Nueva Esperanza", 1, 4.6));
    s2->agregarEpisodio(Episodio("La Búsqueda", 2, 4.3));
    videos.push_back(s2);

    Serie* s3 = new Serie("S003", "Breaking Bad", 47, "drama");
    s3->agregarEpisodio(Episodio("Piloto", 1, 4.8));
    s3->agregarEpisodio(Episodio("Proceso Químico", 1, 4.7));
    videos.push_back(s3);

    Serie* s4 = new Serie("S004", "Friends", 22, "comedia");
    s4->agregarEpisodio(Episodio("La Tormenta", 1, 4.5));
    s4->agregarEpisodio(Episodio("La Mudanza", 2, 4.4));
    videos.push_back(s4);

    Serie* s5 = new Serie("S005", "The Office", 23, "comedia");
    s5->agregarEpisodio(Episodio("La Entrevista", 1, 4.6));
    s5->agregarEpisodio(Episodio("Fiesta de Oficina", 3, 4.5));
    videos.push_back(s5);

    Serie* s6 = new Serie("S006", "The Crown", 60, "drama");
    s6->agregarEpisodio(Episodio("Coronacion", 1, 4.7));
    s6->agregarEpisodio(Episodio("Escandalo Real", 2, 4.6));
    videos.push_back(s6);

    Serie* s7 = new Serie("S007", "La Casa de Papel", 50, "suspenso");
    s7->agregarEpisodio(Episodio("Robo Historico", 1, 4.8));
    s7->agregarEpisodio(Episodio("El Plan", 2, 4.9));
    videos.push_back(s7);

    Serie* s8 = new Serie("S008", "The Flash", 43, "accion");
    s8->agregarEpisodio(Episodio("La Partida de Barry", 1, 4.6));
    s8->agregarEpisodio(Episodio("Fuerza de la Naturaleza", 2, 4.5));
    s8->agregarEpisodio(Episodio("El Hombre del Futuro", 3, 4.7));
    s8->agregarEpisodio(Episodio("Vuelta a la Velocidad", 4, 4.8));
    videos.push_back(s8);
}

/**
     Muestra videos filtrados por calificación mínima o género
 */
void mostrarPorCalifGenero() {
    int op;
    cout << "1. Por calificacion\n2. Por genero\nOpcion: ";
    cin >> op;

    if (op == 1) {
        double calif;
        cout << "Calificacion minima: ";
        cin >> calif;

        for (auto vid : videos)
            if (vid->obtenerCalPromedio() >= calif)
                vid->mostrarInfo();
    } else if (op == 2) {
        string genero;
        cin.ignore();
        cout << "Genero: ";
        getline(cin, genero);

        for (auto vid : videos)
            if (vid->getGenero() == genero)
                vid->mostrarInfo();
    } else {
        cout << "Opcion invalida.\n";
    }
}

/**
       Muestra los episodios de una serie con calificación mayor o igual a un valor dado
 */
void mostrarEpsSerie() {
    string titulo;
    double calif;

    cin.ignore();
    cout << "Titulo de la serie: ";
    getline(cin, titulo);
    cout << "Calificacion minima del episodio: ";
    cin >> calif;

    for (auto vid : videos) {
        Serie* s = dynamic_cast<Serie*>(vid);
        if (s && s->getTitulo() == titulo) {
            s->mostrarEpsCalificados(calif);
        }
    }
}

/**
     Muestra películas con calificación mínima
 */
void mostrarPelsPorCalif() {
    double calif;
    cout << "Calificacion minima: ";
    cin >> calif;

    for (auto vid : videos) {
        Pelicula* p = dynamic_cast<Pelicula*>(vid);
        if (p && p->obtenerCalPromedio() >= calif)
            p->mostrarInfo();
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
        if (vid->getTitulo() == titulo) {
            vid->calificar(valor);
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
    cargarDatos();

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
                mostrarPorCalifGenero();
                break;
            case 3:
                mostrarEpsSerie();
                break;
            case 4:
                mostrarPelsPorCalif();
                break;
            case 5:
                calificarVideo();
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
