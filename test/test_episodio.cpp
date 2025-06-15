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