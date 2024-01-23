#include "core/Application.h"

int main(int argc, char** argv) {
    Application app = Application(&argc, argv);
    app.run();
}