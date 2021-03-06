#ifndef FIDUCIAL_HPP // header guards
#define FIDUCIAL_HPP

#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include <SerialStream.h>
#include <math.h>
#include <unistd.h>

#define PORT "/dev/ttyACM0" //May be ttyACM1 - check Arduino

using namespace std;
using namespace cv;
using namespace LibSerial;

namespace {
const char* about = "Basic marker detection";
const char* keys  =
        "{d        |       | dictionary: DICT_4X4_50=0, DICT_4X4_100=1, DICT_4X4_250=2,"
        "DICT_4X4_1000=3, DICT_5X5_50=4, DICT_5X5_100=5, DICT_5X5_250=6, DICT_5X5_1000=7, "
        "DICT_6X6_50=8, DICT_6X6_100=9, DICT_6X6_250=10, DICT_6X6_1000=11, DICT_7X7_50=12,"
        "DICT_7X7_100=13, DICT_7X7_250=14, DICT_7X7_1000=15, DICT_ARUCO_ORIGINAL = 16}"
        "{ci       | 0     | Camera id if input doesnt come from video (-v) }"
        "{l        | 0.1   | Marker side lenght (in meters). Needed for correct scale in camera pose }";
}

/** Global variables **/
const float marker_width_m = 0.06;
const float focal_length_m = 0.004;
const float sensor_width_m = 0.0055;
const float frame_width_px = 320;
const float deadzone_multiplier = 1; // allow marker this range of motion before controls work

/** Function Headers */
Point2f get_lean(vector<Point2f> corners, Point2f neutral);
Point2f get_neutral(vector<Point2f> corners);

#endif
