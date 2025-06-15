#include <gtest/gtest.h>
#include "clases.h"
#include <sstream>

/**
 * @brief Captura temporalmente la salida de consola
 * @return La salida capturada como string
 */
string capturarSalida(function<void()> funcion) {

    streambuf* oldCoutBuffer = cout.rdbuf();
    ostringstream mockCout;
    cout.rdbuf(mockCout.rdbuf());

    funcion();

    cout.rdbuf(oldCoutBuffer);

    return mockCout.str();
}

//
// Pruebas para la clase Serie
//

TEST(SerieTest, ConstructorInicializaAtributos) {
    Serie s("S001", "Stranger Things", 50, "misterio");

    EXPECT_EQ(s.GetTitulo(), "Stranger Things");
    EXPECT_EQ(s.GetGenero(), "misterio");
    EXPECT_DOUBLE_EQ(s.ObtenerDuracion(), 50);
    EXPECT_TRUE(s.GetEpisodios().empty());
}

TEST(SerieTest, AgregarEpisodio_AgregaCorrectamente) {
    Serie s("S002", "The Mandalorian", 45, "accion");
    Episodio ep1("Una Nueva Esperanza", 1, 4.6);
    Episodio ep2("La Búsqueda", 2, 4.3);

    s.AgregarEpisodio(ep1);
    s.AgregarEpisodio(ep2);

    EXPECT_EQ(s.GetEpisodios().size(), 2);
    EXPECT_EQ(s.GetEpisodios()[0].GetTitulo(), "Una Nueva Esperanza");
    EXPECT_EQ(s.GetEpisodios()[1].GetTitulo(), "La Búsqueda");
}

TEST(SerieTest, MostrarInfo_MuestraInformacion) {
    Serie s("S003", "Breaking Bad", 47, "drama");

    string salida = capturarSalida([&s]() {
        s.MostrarInfo();
    });

    EXPECT_NE(salida.find("Serie: Breaking Bad"), string::npos);
    EXPECT_NE(salida.find("Genero: drama"), string::npos);
    EXPECT_NE(salida.find("Calificacion: 0"), string::npos); 
}

TEST(SerieTest, MostrarEpsCalificados_FiltraPorCalificacion) {
    Serie s("S004", "Friends", 22, "comedia");
    s.AgregarEpisodio(Episodio("La Tormenta", 1, 4.5));
    s.AgregarEpisodio(Episodio("La Mudanza", 2, 4.4));

    string salida = capturarSalida([&s]() {
        s.MostrarEpsCalificados(4.5);
    });

    EXPECT_NE(salida.find("La Tormenta"), string::npos);
    EXPECT_EQ(salida.find("La Mudanza"), string::npos);
}