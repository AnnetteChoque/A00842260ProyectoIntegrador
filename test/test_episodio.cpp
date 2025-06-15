#include <gtest/gtest.h>
#include "clases.h"

TEST(EpisodioTest, AccesoAtributos) {
    Episodio e("El origen", 1, 4.5);
    EXPECT_EQ(e.getTitulo(), "El origen");
    EXPECT_EQ(e.getTemporada(), 1);
    EXPECT_DOUBLE_EQ(e.getCalificacion(), 4.5);
}
