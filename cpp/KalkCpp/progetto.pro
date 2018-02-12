#-------------------------------------------------
#
# Kalk Project di Francesco De Filippis e Michele Roverato
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KalkCpp
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    Shape/shape.cpp \
    Color/colorrgb.cpp \
    Color/colorrgba.cpp \
    Shape/point2d.cpp \
    Shape/point3d.cpp \
    Shape/Shape2D/shape2d.cpp \
    Shape/Shape3D/shape3d.cpp \
    Shape/Shape2D/Polygon/polygon.cpp \
    Shape/Shape2D/Polygon/Quadrilateral/quadrilateral.cpp \
    Shape/Shape2D/Polygon/Quadrilateral/square.cpp \
    Shape/Shape2D/Polygon/Quadrilateral/rectangle.cpp \
    Shape/Shape2D/Polygon/Triangle/triangle.cpp \
    Shape/Shape2D/Polygon/Triangle/righttriangle.cpp \
    Shape/Shape2D/Polygon/Triangle/isoscelestriangle.cpp \
    Shape/Shape3D/RotationSolid/sphere.cpp \
    Shape/Shape3D/Polyhedron/cube.cpp \
    Shape/Shape3D/Polyhedron/polyhedron.cpp \
    Shape/Shape3D/RotationSolid/rotationsolid.cpp \
    Shape/Shape2D/circle.cpp \
    Shape/Shape3D/RotationSolid/cylinder.cpp \
    UI/calculatormaininterface.cpp \
    UI/Utils/imagelabel.cpp \
    UI/Utils/calcbutton.cpp \
    UI/CalculatorInterface/calculatorinterface2d.cpp \
    UI/CalculatorInterface/calculatorinterface3d.cpp \
    UI/CalculatorInterface/calculatordrawinterface.cpp \
    UI/OtherWindows/aboutuswindow.cpp \
    UI/CalculatorInterface/Display/calculatordisplay.cpp \
    UI/CalculatorInterface/Operations/calculatoroperations.cpp \
    UI/CreateShape_Windows/createshape.cpp \
    UI/OtherWindows/guidewindow.cpp \
    UI/AboutShape_Windows/moreinfoshape.cpp \
    UI/OtherWindows/settingswindow.cpp \
    UI/CalculatorInterface/Shapes/shapepanel.cpp \
    UI/CalculatorInterface/Shapes/shapepanel2d.cpp \
    UI/CalculatorInterface/Shapes/shapepanel3d.cpp \
    UI/AboutShape_Windows/about2dcircle.cpp \
    UI/AboutShape_Windows/about2drectangular.cpp \
    UI/AboutShape_Windows/about2dsquare.cpp \
    UI/AboutShape_Windows/about2dtriangleiso.cpp \
    UI/AboutShape_Windows/about2dtriangleret.cpp \
    UI/AboutShape_Windows/about3dcube.cpp \
    UI/AboutShape_Windows/about3dcylinder.cpp \
    UI/AboutShape_Windows/about3dsphere.cpp \
    UI/CreateShape_Windows/create2dcircle.cpp \
    UI/CreateShape_Windows/create2drectangular.cpp \
    UI/CreateShape_Windows/create2dsquare.cpp \
    UI/CreateShape_Windows/create2dtriangleiso.cpp \
    UI/CreateShape_Windows/create2dtriangleret.cpp \
    UI/CreateShape_Windows/create3dcube.cpp \
    UI/CreateShape_Windows/create3dcylinder.cpp \
    UI/CreateShape_Windows/create3dsphere.cpp \
    Controller/Controller2D/squarecontroller.cpp \
    View/shapeview.cpp \
    View/Shape2DView/shape2dview.cpp \
    View/Shape2DView/squareview.cpp \
    Controller/Controller2D/shape2dcontroller.cpp \
    Controller/shapecontroller.cpp \
    View/Shape2DView/rectangleview.cpp \
    View/Shape2DView/circleview.cpp \
    View/Shape2DView/triangleisoview.cpp \
    View/Shape2DView/triangleretview.cpp \
    View/Shape3DView/shape3dview.cpp \
    View/Shape3DView/cubeview.cpp \
    View/Shape3DView/cylinderview.cpp \
    View/Shape3DView/sphereview.cpp \
    Controller/Controller3D/shape3dcontroller.cpp \
    Controller/Controller2D/circlecontroller.cpp \
    Controller/Controller2D/rectanglecontroller.cpp \
    Controller/Controller2D/triangleisocontroller.cpp \
    Controller/Controller2D/triangleretcontroller.cpp \
    Controller/Controller3D/cubecontroller.cpp \
    Controller/Controller3D/cylindercontroller.cpp \
    Controller/Controller3D/spherecontroller.cpp \
    UI/CalculatorInterface/Operations/calculatoroperations2d.cpp \
    UI/Translate_Windows/translateinput.cpp \
    UI/Translate_Windows/translateshapeselector.cpp

HEADERS += \
    Shape/shape.h \
    Color/colorrgb.h \
    Color/colorrgba.h \
    Shape/point2d.h \
    Shape/point3d.h \
    Shape/Shape2D/shape2d.h \
    Shape/Shape3D/shape3d.h \
    Shape/Shape2D/Polygon/polygon.h \
    Shape/Shape2D/Polygon/Quadrilateral/quadrilateral.h \
    Shape/Shape2D/Polygon/Quadrilateral/square.h \
    Shape/Shape2D/Polygon/Quadrilateral/rectangle.h \
    Shape/Shape2D/Polygon/Triangle/triangle.h \
    Shape/Shape2D/Polygon/Triangle/righttriangle.h \
    Shape/Shape2D/Polygon/Triangle/isoscelestriangle.h \
    Shape/Shape3D/RotationSolid/sphere.h \
    Shape/Shape3D/Polyhedron/cube.h \
    Shape/Shape3D/Polyhedron/polyhedron.h \
    Shape/Shape3D/RotationSolid/rotationsolid.h \
    Shape/Shape2D/circle.h \
    Shape/Shape3D/RotationSolid/cylinder.h \
    UI/calculatormaininterface.h \
    UI/Utils/imagelabel.h \
    UI/Utils/calcbutton.h \
    UI/CalculatorInterface/calculatorinterface2d.h \
    UI/CalculatorInterface/calculatorinterface3d.h \
    UI/CalculatorInterface/calculatordrawinterface.h \
    UI/OtherWindows/aboutuswindow.h \
    UI/CalculatorInterface/Display/calculatordisplay.h \
    UI/CalculatorInterface/Operations/calculatoroperations.h \
    UI/CreateShape_Windows/createshape.h \
    UI/OtherWindows/guidewindow.h \
    UI/AboutShape_Windows/moreinfoshape.h \
    UI/OtherWindows/settingswindow.h \
    UI/CalculatorInterface/Shapes/shapepanel.h \
    UI/CalculatorInterface/Shapes/shapepanel2d.h \
    UI/CalculatorInterface/Shapes/shapepanel3d.h \
    UI/AboutShape_Windows/about2dcircle.h \
    UI/AboutShape_Windows/about2drectangular.h \
    UI/AboutShape_Windows/about2dsquare.h \
    UI/AboutShape_Windows/about2dtriangleiso.h \
    UI/AboutShape_Windows/about2dtriangleret.h \
    UI/AboutShape_Windows/about3dcube.h \
    UI/AboutShape_Windows/about3dcylinder.h \
    UI/AboutShape_Windows/about3dsphere.h \
    UI/CreateShape_Windows/create2dcircle.h \
    UI/CreateShape_Windows/create2drectangular.h \
    UI/CreateShape_Windows/create2dsquare.h \
    UI/CreateShape_Windows/create2dtriangleiso.h \
    UI/CreateShape_Windows/create2dtriangleret.h \
    UI/CreateShape_Windows/create3dcube.h \
    UI/CreateShape_Windows/create3dcylinder.h \
    UI/CreateShape_Windows/create3dsphere.h \
    Controller/Controller2D/squarecontroller.h \
    View/shapeview.h \
    View/Shape2DView/shape2dview.h \
    View/Shape2DView/squareview.h \
    Controller/Controller2D/shape2dcontroller.h \
    Controller/shapecontroller.h \
    View/Shape2DView/rectangleview.h \
    View/Shape2DView/circleview.h \
    View/Shape2DView/triangleisoview.h \
    View/Shape2DView/triangleretview.h \
    View/Shape3DView/shape3dview.h \
    View/Shape3DView/cubeview.h \
    View/Shape3DView/cylinderview.h \
    View/Shape3DView/sphereview.h \
    Controller/Controller3D/shape3dcontroller.h \
    Controller/Controller2D/circlecontroller.h \
    Controller/Controller2D/rectanglecontroller.h \
    Controller/Controller2D/triangleisocontroller.h \
    Controller/Controller2D/triangleretcontroller.h \
    Controller/Controller3D/cubecontroller.h \
    Controller/Controller3D/cylindercontroller.h \
    Controller/Controller3D/spherecontroller.h \
    UI/CalculatorInterface/Operations/calculatoroperations2d.h \
    UI/Translate_Windows/translateinput.h \
    UI/Translate_Windows/translateshapeselector.h


FORMS +=

RESOURCES += \
    ui_resources.qrc
