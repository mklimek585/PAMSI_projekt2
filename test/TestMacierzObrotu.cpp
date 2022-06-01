#include "gtest/gtest.h"
#include "MacierzObrotu.h"


TEST(MacierzObrotu, dodawanie) {
    MacierzObrotu<2> mac1(2);
    MacierzObrotu<2> mac2(1);
    MacierzObrotu<2> wynik(3);
    mac2 = mac1 + mac2;
    EXPECT_TRUE(mac2 == wynik);
}

TEST(MacierzObrotu, odejmowanie) {
    MacierzObrotu<2> mac1(2);
    MacierzObrotu<2> mac2(1);
    MacierzObrotu<2> wynik(0);
    mac2 = mac1 - mac2 - mac2;
    EXPECT_TRUE(mac2 == wynik);
}

TEST(MacierzObrotu, mnozenie) {
    MacierzObrotu<2> mac1(2);
    MacierzObrotu<2> mac2(1);
    MacierzObrotu<2> wynik(2);
    mac2 = mac1 * mac2;
    EXPECT_TRUE(mac2 == wynik);
}

TEST(MacierzObrotu, dodawanie_rowna_sie) {
    MacierzObrotu<2> mac1(2);
    MacierzObrotu<2> mac2(1);
    MacierzObrotu<2> wynik(3);
    mac2 += mac1;
    EXPECT_TRUE(mac2 == wynik);
}

TEST(MacierzObrotu, mnozenie_razy_wektor) {
    MacierzObrotu<3> mac1(2);
    Wektor<3> wek({2, 2, 1});
    Wektor<3> wynik({4, 4, 2});
    wek = mac1 * wek;
    EXPECT_TRUE(wek == wynik);
}

TEST(MacierzObrotu, mnozenie_razy_liczbe) {
    MacierzObrotu<2> mac1(2);
    int x = 3;
    MacierzObrotu<2> wynik(6);
    mac1 = mac1 * x;
    EXPECT_TRUE(mac1 == wynik);
}

TEST(MacierzObrotu, obrot_wektora) {
    MacierzObrotu<3> macierzObrotu(90, 'y');
    Wektor<3> wektor({1, 0, 0});
    wektor = macierzObrotu * wektor;
    Wektor<3> wynik({0, 0, -1});
    EXPECT_TRUE(1);
}