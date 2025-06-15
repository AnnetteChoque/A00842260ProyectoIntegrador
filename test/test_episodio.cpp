#include <gtest/gtest.h>
#include "clases.h"

TEST(SerieTest, AgregarEpisodios) {
    Serie s("S001", "Stranger Things", 50, "misterio");
    s.agregarEpisodio(Episodio("Capitulo Uno", 1, 4.5));
    s.agregarEpisodio(Episodio("Capitulo Dos", 1, 4.7));

    testing::internal::CaptureStdout();
    s.mostrarEpsCalificados(4.0);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Capitulo Uno"), string::npos);
    EXPECT_NE(output.find("Capitulo Dos"), string::npos);
}

TEST(SerieTest, FiltrarEpisodiosPorCalificacion) {
    Serie s("S002", "The Mandalorian", 45, "accion");
    s.agregarEpisodio(Episodio("Una Nueva Esperanza", 1, 4.6));
    s.agregarEpisodio(Episodio("La Búsqueda", 2, 4.3));

    testing::internal::CaptureStdout();
    s.mostrarEpsCalificados(4.5);
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Una Nueva Esperanza"), string::npos);
    EXPECT_EQ(output.find("La Búsqueda"), string::npos);
}