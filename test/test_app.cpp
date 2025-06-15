//
// Created by Annette on 14/06/2025.
//

#include <gtest/gtest.h>
#include "clases.h"
#include <sstream>

// Vector global de prueba
vector<Video*> videos;

// Funciones globales para probar
void CargarDatos(vector<Video*>& videos) {
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

// ---------------------
// Redirección de cin/cout
// ---------------------

/**
 * @brief Simula una entrada de texto
 */
class InputSimulator {
private:
    std::istringstream input;
public:
    InputSimulator(const std::string& data) : input(data) {
        oldBuffer = std::cin.rdbuf(input.rdbuf());
    }

    ~InputSimulator() {
        std::cin.rdbuf(oldBuffer);
    }

private:
    std::streambuf* oldBuffer;
};

/**
 * @brief Captura la salida de cout
 */
class OutputCapturer {
public:
    OutputCapturer() {
        oldBuffer = std::cout.rdbuf();
        cout.rdbuf(buffer.rdbuf());
    }

    ~OutputCapturer() {
        std::cout.rdbuf(oldBuffer);
    }

    std::string GetOutput() {
        return buffer.str();
    }

private:
    std::ostringstream buffer;
    std::streambuf* oldBuffer;
};

// ---------------------
// Pruebas reales
// ---------------------

/**
 * @brief Valida que los datos se carguen correctamente
 */
TEST(MainTest, CargarDatos_NoCrashea) {
    vector<Video*> videos;
    CargarDatos(videos);

    EXPECT_EQ(videos.size(), 16); // 8 películas + 8 series

    for (auto v : videos)
        delete v;
}

/**
 * @brief MostrarPorCalifGenero muestra películas con cierta calificación
 */
TEST(MainTest, MostrarPorCalifGenero_PorCalificacion) {
    vector<Video*> videos;
    CargarDatos(videos);

    OutputCapturer cap;
    InputSimulator in("1\n4.5\n"); // Opción 1, calificación 4.5

    MostrarPorCalifGenero();

    string output = cap.GetOutput();

    EXPECT_NE(output.find("Inception"), string::npos);
    EXPECT_NE(output.find("El Padrino"), string::npos);
    EXPECT_NE(output.find("The Dark Knight"), string::npos);
    EXPECT_EQ(output.find("Forrest Gump"), string::npos); // 4.75 promedio → no debe salir

    for (auto v : videos)
        delete v;
}

/**
 * @brief MostrarPorCalifGenero filtra por género
 */
TEST(MainTest, MostrarPorCalifGenero_PorGenero) {
    vector<Video*> videos;
    CargarDatos(videos);

    InputSimulator in("2\naccion\n"); // Opción 2, género accion
    OutputCapturer cap;

    MostrarPorCalifGenero();

    string output = cap.GetOutput();

    EXPECT_NE(output.find("Inception"), string::npos);
    EXPECT_NE(output.find("The Dark Knight"), string::npos);
    EXPECT_NE(output.find("Avengers Endgame"), string::npos);
    EXPECT_EQ(output.find("Stranger Things"), string::npos); // No es acción

    for (auto v : videos)
        delete v;
}

/**
 * @brief CalificarVideo funciona correctamente
 */
TEST(MainTest, CalificarVideo_CalificaBien) {
    vector<Video*> videos;
    CargarDatos(videos);

    InputSimulator in("The Dark Knight\n5\n"); // Titulo y calificación
    OutputCapturer cap;

    CalificarVideo();

    string output = cap.GetOutput();

    EXPECT_NE(output.find("Calificacion agregada."), string::npos);

    // Buscar película y verificar calificación
    bool encontrado = false;
    for (auto v : videos) {
        if (v->GetTitulo() == "The Dark Knight") {
            EXPECT_DOUBLE_EQ(v->ObtenerCalPromedio(), 4.5); // Era 4.5 antes, ahora 5
            encontrado = true;
        }
    }

    EXPECT_TRUE(encontrado);

    for (auto v : videos)
        delete v;
}

/**
 * @brief MostrarEpsSerie filtra bien
 */
TEST(MainTest, MostrarEpsSerie_FiltraPorCalificacion) {
    vector<Video*> videos;
    CargarDatos(videos);

    InputSimulator in("Stranger Things\n4.6\n"); // Título y calificación
    OutputCapturer cap;

    MostrarEpsSerie();

    string output = cap.GetOutput();

    EXPECT_NE(output.find("Capitulo Dos"), string::npos); // Tiene 4.7
    EXPECT_EQ(output.find("Capitulo Uno"), string::npos); // Solo 4.5 → no debe aparecer

    for (auto v : videos)
        delete v;
}

/**
 * @brief MostrarPelsPorCalif muestra solo películas con cierta calificación
 */
TEST(MainTest, MostrarPelsPorCalif_FiltraCorrectamente) {
    vector<Video*> videos;
    CargarDatos(videos);

    OutputCapturer cap;

    void (*ptr)(double) = reinterpret_cast<void(*)(double)>(reinterpret_cast<void*>(&MostrarPelsPorCalif)); // Para evitar modificar función original
    ptr(4.7); // Llamamos directamente con umbral de 4.7

    string output = cap.GetOutput();

    EXPECT_NE(output.find("Titanic"), string::npos);     // 4.8 promedio
    EXPECT_NE(output.find("Gladiator"), string::npos);   // 4.8 promedio
    EXPECT_EQ(output.find("Inception"), string::npos);  // 4.5 → no debe aparecer

    for (auto v : videos)
        delete v;
}