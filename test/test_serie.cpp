//
// Created by Annette on 14/06/2025.
//

TEST(SerieTest, PromedioConEpisodios) {
    Serie s("S001", "Dark", 60, "misterio");
    s.agregarEpisodio(Episodio("Capitulo 1", 1, 4.0));
    s.agregarEpisodio(Episodio("Capitulo 2", 1, 5.0));
    EXPECT_DOUBLE_EQ(s.obtenerCalPromedio(), 4.5);
}

TEST(SerieTest, PromedioSinEpisodios) {
    Serie s("S002", "SinEpisodios", 50, "drama");
    EXPECT_DOUBLE_EQ(s.obtenerCalPromedio(), 0.0);
}

TEST(SerieTest, MostrarSerieConEpisodios) {
    Serie s("S003", "The Witcher", 55, "fantasia");
    s.agregarEpisodio(Episodio("El principio", 1, 4.2));
    EXPECT_NO_THROW(s.mostrarInfo());
}

TEST(SerieTest, MostrarSerieSinEpisodios) {
    Serie s("S004", "Vacía", 50, "drama");
    EXPECT_NO_THROW(s.mostrarInfo());
}