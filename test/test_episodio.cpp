#include <gtest/gtest.h>
#include "clases.h"

TEST(SerieTest, AgregarEpisodios) {
    Serie s("S001", "Stranger Things", 50, "misterio");
    s.AgregarEpisodio(Episodio("Capitulo Uno", 1, 4.5));
    s.AgregarEpisodio(Episodio("Capitulo Dos", 1, 4.7));

    EXPECT_EQ(s.ObtenerCalPromedio(), 0);
}

TEST(SerieTest, FiltrarEpisodiosPorCalificacion) {
    Serie s("S002", "The Mandalorian", 45, "accion");
    s.AgregarEpisodio(Episodio("Una Nueva Esperanza", 1, 4.6));
    s.AgregarEpisodio(Episodio("La Búsqueda", 2, 4.3));

    testing::internal::CaptureStdout();
    s.MostrarEpsCalificados(4.5);
    std::string output = testing::internal::GetCapturedStdout();
}
