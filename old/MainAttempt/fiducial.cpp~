#include "fiducial.hpp"

Point2f get_neutral(vector<Point2f> c) {

    Point2f neutral;
    float av_marker_width = 0;
    float av_roll_location = 0;
   
    cout << "Calibrating neutral position. Hold still..." << endl;

    for(int i = 1; i < 101; i++) { // collect a data point approx. every 10ms, 20 times

        // Get pixel size of marker
        av_marker_width += sqrt( (c[1].x - c[0].x) * (c[1].x - c[0].x) + (c[1].y - c[0].y) * (c[1].y - c[0].y) )/i; 
        
        // left-right pixel location of marker center
        av_roll_location += (c[0].x + c[1].x)/(2*i); 

        usleep(10000);    
       
    } 
    
    float av_pitch_location = (focal_length_m * frame_width_px * marker_width_m)/(av_marker_width * sensor_width_m);

    neutral.x = av_roll_location;
    neutral.y = av_pitch_location;

    cout << "Neutral position calibrated: average roll location = " << av_roll_location <<  " average pitch location = " << av_pitch_location << endl;
	cout << "Beginning simulation..." << endl;

    return neutral;
    
}


Point2f get_lean(vector<Point2f> c, Point2f n) {   

    Point2f lean;

    float neutral_x = n.x;
    float neutral_z = n.y;
    
    // Get pixel size and location of marker
    float marker_width_px = sqrt( (c[1].x - c[0].x) * (c[1].x - c[0].x) + (c[1].y - c[0].y) * (c[1].y - c[0].y) ); 
    float x_location_px = (c[0].x + c[1].x)/2; // plz find actual middle of square    

    // get x location as pixel displacement from neutral  
    float x_displacement_px = x_location_px - neutral_x;  
    
    // do pinhole projection calcs to convert px to m
    float z_dist_m = (focal_length_m * frame_width_px * marker_width_m)/(marker_width_px * sensor_width_m); // pitch
    float x_dist_m = (x_displacement_px * sensor_width_m * z_dist_m)/(focal_length_m * frame_width_px); // roll  

    // get z location as displacement from neutral
    float z_disp_m = z_dist_m - neutral_z; 

    lean.x = x_dist_m;
    lean.y = z_disp_m; // yes, this is somewhat confusing, sue me

    return lean;
}

/* For the z-distance, we should do a button press interrupt with the arduino
so that the user can set the size at a neutral postion, all the way forward and all
the way back. Or we can just set it arbitrarily. */



