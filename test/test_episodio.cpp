#include <gtest/gtest.h>
#include "clases.h"

TEST(SerieTest, AgregarEpisodios) {
    Serie s("S001", "Stranger Things", 50, "misterio");
    s.agregarEpisodio(Episodio("Capitulo Uno", 1, 4.5));
    s.agregarEpisodio(Episodio("Capitulo Dos", 1, 4.7));

    EXPECT_EQ(s.obtenerCalPromedio(), 0);
}

TEST(SerieTest, FiltrarEpisodiosPorCalificacion) {
    Serie s("S002", "The Mandalorian", 45, "accion");
    s.agregarEpisodio(Episodio("Una Nueva Esperanza", 1, 4.6));
    s.agregarEpisodio(Episodio("La Búsqueda", 2, 4.3));

    testing::internal::CaptureStdout();
    s.mostrarEpsCalificados(4.5);
    std::string output = testing::internal::GetCapturedStdout();
}
