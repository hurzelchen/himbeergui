CONFIG += c++17

equals(QT_ARCH, arm64) {
    LIBS += -L/usr/lib/aarch64-linux-gnu/
}
