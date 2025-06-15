#include <gtest/gtest.h>
#include "clases.h"
#include <sstream>

TEST(SerieTest, Constructor_HerenciaCorrecta) {
    Serie s("S001", "Stranger Things", 50, "misterio");

    EXPECT_EQ(s.GetTitulo(), "Stranger Things");
    EXPECT_EQ(s.GetGenero(), "misterio");
}

TEST(SerieTest, AgregarEpisodio_NoCrashea) {
    Serie s("S002", "The Mandalorian", 45, "accion");
    Episodio ep1("Una Nueva Esperanza", 1, 4.6);
    Episodio ep2("La Búsqueda", 2, 4.3);

    s.AgregarEpisodio(ep1);
    s.AgregarEpisodio(ep2);

    EXPECT_TRUE(true);
}

TEST(SerieTest, MostrarEpsCalificados_NoCrashea) {
    Serie s("S003", "Breaking Bad", 47, "drama");
    s.AgregarEpisodio(Episodio("Piloto", 1, 4.8));
    s.AgregarEpisodio(Episodio("Proceso Químico", 1, 4.3));

    testing::internal::CaptureStdout(); // Captura la salida de consola
    s.MostrarEpsCalificados(4.5);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty()); // Asumimos que imprimió algo
}

// Función auxiliar para capturar salida de cout
std::string capturarSalida(std::function<void()> funcion) {
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::ostringstream mockCout;
    std::cout.rdbuf(mockCout.rdbuf());

    funcion();

    std::cout.rdbuf(oldCoutBuffer);

    return mockCout.str();
}

// Prueba: Agregar episodios correctamente
TEST(SerieTest, AgregarEpisodios_AgregaCorrectamente) {
    Serie s("S001", "Stranger Things", 50, "misterio");
    Episodio ep1("Capitulo Uno", 1, 4.5);
    Episodio ep2("Capitulo Dos", 1, 4.7);

    s.AgregarEpisodio(ep1);
    s.AgregarEpisodio(ep2);

    EXPECT_EQ(s.GetEpisodios().size(), 2);
    EXPECT_EQ(s.GetEpisodios()[0].GetTitulo(), "Capitulo Uno");
    EXPECT_EQ(s.GetEpisodios()[1].GetTitulo(), "Capitulo Dos");
}

// Prueba: MostrarInfo muestra la información básica
TEST(SerieTest, MostrarInfo_MuestraInformacion) {
    Serie s("S002", "The Mandalorian", 45, "accion");

    // Calificar la serie
    s.Calificar(4.6); // Simula calificaciones
    s.Calificar(4.8);

    string salida = capturarSalida([&s]() {
        s.MostrarInfo();
    });

    EXPECT_NE(salida.find("Serie: The Mandalorian"), string::npos);
    EXPECT_NE(salida.find("Genero: accion"), string::npos);
    EXPECT_NE(salida.find("Calificacion: 4.7"), string::npos); // Promedio de 4.6 y 4.8
}

// Prueba: MostrarEpsCalificados filtra correctamente
TEST(SerieTest, MostrarEpsCalificados_FiltraPorCalificacion) {
    Serie s("S003", "Friends", 22, "comedia");
    s.AgregarEpisodio(Episodio("La Tormenta", 1, 4.5));
    s.AgregarEpisodio(Episodio("La Mudanza", 2, 4.4));

    string salida = capturarSalida([&s]() {
        s.MostrarEpsCalificados(4.5);
    });

    EXPECT_NE(salida.find("La Tormenta"), string::npos);     // Debe aparecer
    EXPECT_EQ(salida.find("La Mudanza"), string::npos);      // No debe aparecer
}