#include <pebble.h>
#include "my_math.h"
#include "settings.h"


#include "colordefs.h"
  
static int get_star_x(float sunL, float latecl, float lonecl) {
    float angle = sunL - lonecl;
    float rad;
  
   if (flip_horizontally == flip_horizontally_yes) {
     rad = 66 - latecl;
     return my_rint(72 - (sind(angle) * rad));    
   }
    rad = 66 + latecl;
    return my_rint(72 + (sind(angle) * rad));
 
}

static int get_star_y(float sunL, float latecl, float lonecl) {
    float angle = sunL - lonecl;
    float rad;
  
  if (flip_horizontally == flip_horizontally_yes) {
     rad = 66 - latecl;
  }
  else { rad = 66 + latecl; }
  return my_rint(84 - (cosd(angle) * rad));
}




static void draw_const_line(GContext *ctx, float sunL, float latecl1, float lonecl1, float latecl2, float lonecl2) {
    int x1 = get_star_x(sunL, latecl1, lonecl1);
    int y1 = get_star_y(sunL, latecl1, lonecl1);
    int x2 = get_star_x(sunL, latecl2, lonecl2);
    int y2 = get_star_y(sunL, latecl2, lonecl2);
    graphics_context_set_stroke_color(ctx, CONST_LINE_COLOR);
    graphics_draw_line(ctx, GPoint(x1, y1), GPoint(x2, y2));
    
}


static void draw_const_lines(GContext *ctx, float sunL) {
  
  //Libra
  draw_const_line(ctx, sunL, 3.4378, 239.8737, 4.3537, 235.1397);
  draw_const_line(ctx, sunL, 4.3537, 235.1397, 8.4661, 229.3755);
  draw_const_line(ctx, sunL, 8.4661, 229.3755, 0.3053, 225.0828);
  draw_const_line(ctx, sunL, 0.3053, 225.0828, -7.6749, 230.6839);
  draw_const_line(ctx, sunL, -7.6749, 230.6839, 4.3537, 235.1397);

  //Virgo
  draw_const_line(ctx, sunL, -2.0704, 203.8401, 2.7834, 190.1433 );
  draw_const_line(ctx, sunL, 2.7834, 190.1433, 8.6056, 191.4667 );
  draw_const_line(ctx, sunL, 8.6056, 191.4667, 8.6218, 202.1397);
  draw_const_line(ctx, sunL, 8.6218, 202.1397, -2.0704, 203.8401); 
  draw_const_line(ctx, sunL, 2.8907, 214.4954, -2.0704, 203.8401);
  draw_const_line(ctx, sunL, 8.6218, 202.1397, 13.0443, 207.7568);
  draw_const_line(ctx, sunL, 16.1982, 189.9515, 8.6056, 191.4667);
  draw_const_line(ctx, sunL, 2.7834, 190.1433, 1.3620, 184.8331);
  draw_const_line(ctx, sunL, 1.3620, 184.8331, 4.5903, 174.1624);
  
  //Leo
  draw_const_line(ctx, sunL, 8.8347, 149.6203, 14.3462, 161.3261);
  
  draw_const_line(ctx, sunL, 14.3462, 161.3261, 12.2726, 171.6260);
  draw_const_line(ctx, sunL, 12.2726, 171.6260, 9.6855, 163.4294);
  draw_const_line(ctx, sunL, 9.6855, 163.4294, 0.4846, 149.8294);
  draw_const_line(ctx, sunL, 0.4846, 149.8294, 4.8866, 147.9079);
  draw_const_line(ctx, sunL, 4.8866, 147.9079, 8.8347, 149.6203);
  draw_const_line(ctx, sunL, 8.8347, 149.6203, 11.8861, 147.5724);
  draw_const_line(ctx, sunL, 11.8861, 147.5724, 12.3734, 141.4368);
  draw_const_line(ctx, sunL, 12.3734, 141.4368, 9.7403, 140.7101);
   
  
  // Cancer
  draw_const_line(ctx, sunL, 10.4581, 126.3504, 0.1078, 128.7220);
  draw_const_line(ctx, sunL, 0.1078, 128.7220, -5.0520, 133.6392);
  draw_const_line(ctx, sunL, 0.1078, 128.7220, -10.2551, 124.2533);
  
  // Gemini
  draw_const_line(ctx, sunL, 6.7203, 113.2176, 5.2526, 111.3456);
  draw_const_line(ctx, sunL, 5.2526, 111.3456, -0.1411, 108.5193);
  draw_const_line(ctx, sunL, -0.1411, 108.5193, -6.7038, 99.1039);
  
  draw_const_line(ctx, sunL, -0.1411, 108.5193, -5.5980, 108.7776);
  draw_const_line(ctx, sunL, -5.5980, 108.7776, -10.0657, 101.2079);
  
  draw_const_line(ctx, sunL, 10.1326, 110.2427, 7.7923, 105.4457);
  draw_const_line(ctx, sunL, 7.7923, 105.4457, 2.1087, 99.9390);
  draw_const_line(ctx, sunL, 2.1087, 99.9390, -0.7810, 95.3018);
  draw_const_line(ctx, sunL, -0.7810, 95.3018, -0.8489, 93.4361);
  
  draw_const_line(ctx, sunL, 2.1087, 99.9390, -3.0173, 96.8022);
  
  
  draw_const_line(ctx, sunL, 3.1145, 113.6666, 5.2526, 111.3456);
  draw_const_line(ctx, sunL, 5.2526, 111.3456, 5.7955, 108.9586);
  draw_const_line(ctx, sunL, 5.7955, 108.9586, 7.7923, 105.4457);
  draw_const_line(ctx, sunL, 7.7923, 105.4457, 11.0687, 101.1249);

  
  
  //Taurus
  draw_const_line(ctx, sunL, -2.1565, 84.7848, -5.4305, 69.7905);
  draw_const_line(ctx, sunL, -5.4305, 69.7905, -5.6964, 65.8074);
  draw_const_line(ctx, sunL, -5.6964, 65.8074, -7.9256, 60.6372);
  draw_const_line(ctx, sunL, -7.9256, 60.6372, -9.3036, 51.1676);
  draw_const_line(ctx, sunL, -5.6964, 65.8074, -2.5306, 68.4657);
  draw_const_line(ctx, sunL, -2.5306, 68.4657, 0.7513, 72.1536);
  draw_const_line(ctx, sunL, 0.7513, 72.1536, 5.4241, 82.5745);
  
  draw_const_line(ctx, sunL, -5.4305, 69.7905, -2.5306, 68.4657);
  draw_const_line(ctx, sunL, -2.5306, 68.4657, 3.9516, 60.3546);
  
  
  
  
  //Aries
  draw_const_line(ctx, sunL, 10.4790, 48.1987, 9.9891, 37.6570 );
  draw_const_line(ctx, sunL, 9.9891, 37.6570, 8.5092, 33.9651 );
  draw_const_line(ctx, sunL, 8.5092, 33.9651, 7.1839, 33.1804 );
  
  //Pisces
  draw_const_line(ctx, sunL, 5.3954, 26.8126, -1.6020, 27.7441 );
  draw_const_line(ctx, sunL, -1.6020, 27.7441, -9.0416, 29.3841 );
  draw_const_line(ctx, sunL, -9.0416, 29.3841, -4.6772, 25.5095 );
  draw_const_line(ctx, sunL, -4.6772, 25.5095, 1.1056, 17.5246 );
  draw_const_line(ctx, sunL, 1.1056, 17.5246, 6.3647, 2.5792 );
  draw_const_line(ctx, sunL, 6.3647, 2.5792, 7.1523, 357.6398 );
  draw_const_line(ctx, sunL, 7.1523, 357.6398, 9.0300, 355.1828 );
  draw_const_line(ctx, sunL, 9.0300, 355.1828, 7.2513, 351.4483 );
  draw_const_line(ctx, sunL, 7.2513, 351.4483, 3.4152, 356.5858 );
  draw_const_line(ctx, sunL, 3.4152, 356.5858, 7.1523, 357.6398 );
    
  //Aquarius
  draw_const_line(ctx, sunL, -14.5036, 340.0273, -5.6789, 338.5994 );
  draw_const_line(ctx, sunL, -5.6789, 338.5994, -0.3991, 341.5764 );
  draw_const_line(ctx, sunL, -0.3991, 341.5764, 8.1337, 340.3978 );
  draw_const_line(ctx, sunL, 8.1337, 340.3978, 8.8316, 338.9040 );
  draw_const_line(ctx, sunL, 8.8316, 338.9040,  8.2196, 336.7088 );
  draw_const_line(ctx, sunL, 8.2196, 336.7088, 10.6440, 333.3459 );
  draw_const_line(ctx, sunL, 10.6440, 333.3459, 8.5916, 323.3903 );
  draw_const_line(ctx, sunL, 8.5916, 323.3903, 8.0512, 311.7195 );
  
  //Capricornus
  draw_const_line(ctx, sunL,6.8975, 303.8559, 4.5561, 304.0456 );
  draw_const_line(ctx, sunL, 4.5561, 304.0456, -0.6142, 313.8442 );
  draw_const_line(ctx, sunL, -0.6142, 313.8442, -2.6250, 323.5440);
  draw_const_line(ctx, sunL, -2.6250, 323.5440, -7.0178, 316.9404 );
  draw_const_line(ctx, sunL, -7.0178, 316.9404,  -8.9937, 307.9633);
  draw_const_line(ctx, sunL,-8.9937, 307.9633, 4.5561, 304.0456);
  
  //Sagittarius
  draw_const_line(ctx, sunL, 1.6230, 283.4509, 0.8221, 284.9939 );
  draw_const_line(ctx, sunL, 0.8221, 284.9939, -3.4879, 282.3858);
  draw_const_line(ctx, sunL, -3.4879, 282.3858, -3.9927, 280.1818);
  draw_const_line(ctx, sunL, -3.9927, 280.1818, -2.1747, 276.3173);
  draw_const_line(ctx, sunL, -2.1747, 276.3173, -6.5114, 274.5812);
  draw_const_line(ctx, sunL, -6.5114, 274.5812, -11.0909, 275.0792);
  draw_const_line(ctx, sunL, -11.0909, 275.0792,-13.4171, 273.6284 );
    
  draw_const_line(ctx, sunL, -3.4879, 282.3858, -5.1268, 284.8352);
  draw_const_line(ctx, sunL, -5.1268, 284.8352, -7.2171, 283.6395);
  draw_const_line(ctx, sunL, -2.1747, 276.3173, 2.3029, 273.2134);
  draw_const_line(ctx, sunL, -6.5114, 274.5812, -7.0304, 271.2616);
  
  // Scorpius
  draw_const_line(ctx, sunL, -13.8276, 264.5848, -16.7536, 267.5220 );
  draw_const_line(ctx, sunL, -16.7536, 267.5220, -19.6843, 265.5983 );
  draw_const_line(ctx, sunL, -19.6843, 265.5983, -19.6822, 257.2342);
  draw_const_line(ctx, sunL, -19.6822, 257.2342, -11.7765, 255.3333);
  draw_const_line(ctx, sunL, -11.7765, 255.3333, -4.6068, 249.7612);
  draw_const_line(ctx, sunL, -4.6068, 249.7612, 0.9727, 243.1903);
  draw_const_line(ctx, sunL, -4.6068, 249.7612, -2.0209, 242.5706);
  draw_const_line(ctx, sunL, -4.6068, 249.7612, -5.5104, 242.9382);
}
#ifdef PBL_COLOR

static void draw_star(GContext *ctx, float sunL, float latecl, float lonecl, float mag, float ci) {
  
  GColor color = GColorWhite;
  if ((mag > 2.3) && (mag <= 3.5)) color = GColorLightGray;
  if (mag > 3.5) color = GColorDarkGray;
  if (mag <= 2.3) {
     if (ci > 1) color = GColorOrange;
     if ((ci > 0.5) && (ci <= 1)) color = GColorRajah;
     if (ci < 0) color = GColorElectricBlue;
   }
   graphics_context_set_stroke_color(ctx, color);
    
   graphics_draw_pixel(ctx, GPoint(get_star_x(sunL, latecl, lonecl), get_star_y(sunL, latecl, lonecl)));
}
  
static void draw_stars(GContext *ctx, float sunL) {
  
draw_star(ctx, sunL, -5.7123, 358.0532, 4.37, 1.63);	// HIP154	30    Psc		
draw_star(ctx, sunL, 12.6062, 9.1474, 2.83, -0.19);	// HIP1067	88Gam Peg	Algenib	
draw_star(ctx, sunL, -18.7691, 355.5513, 4.44, 1.64);	// HIP1170	7    Cet		
draw_star(ctx, sunL, -10.0211, 0.9230, 3.56, 1.21);	// HIP1562	8Iot Cet		
draw_star(ctx, sunL, 23.0362, 20.9088, 4.34, 0.87);	// HIP3031	30Eps And		
draw_star(ctx, sunL, 24.3654, 21.7969, 3.27, 1.27);	// HIP3092	31Del And		
draw_star(ctx, sunL, -20.7818, 2.5984, 2.04, 1.02);	// HIP3419	16Bet Cet	Diphda	
draw_star(ctx, sunL, 17.6341, 20.5683, 4.08, 1.10);	// HIP3693	34Zet And		
draw_star(ctx, sunL, 2.1862, 14.1459, 4.44, 1.50);	// HIP3786	63Del Psc		
draw_star(ctx, sunL, 15.9452, 22.3656, 4.40, 0.94);	// HIP4463	38Eta And		
draw_star(ctx, sunL, 1.1056, 17.5246, 4.27, 0.95);	// HIP4906	71Eps Psc		
draw_star(ctx, sunL, -16.1104, 11.7786, 3.46, 1.16);	// HIP5364	31Eta Cet		
draw_star(ctx, sunL, -15.7563, 16.2368, 3.60, 1.07);	// HIP6537	45The Cet		
draw_star(ctx, sunL, 5.3954, 26.8126, 3.62, 0.97);	// HIP7097	99Eta Psc		
draw_star(ctx, sunL, -4.6772, 25.5095, 4.45, 1.35);	// HIP7884	106Nu  Psc		
draw_star(ctx, sunL, -24.8039, 17.8361, 3.49, 0.73);	// HIP8102	52Tau Cet		
draw_star(ctx, sunL, -1.6020, 27.7441, 4.26, 0.94);	// HIP8198	110Omi Psc		
draw_star(ctx, sunL, -20.3199, 21.9636, 3.74, 1.14);	// HIP8645	55Zet Cet		
draw_star(ctx, sunL, 16.8241, 36.8514, 3.42, 0.49);	// HIP8796	2Alp Tri		
draw_star(ctx, sunL, 7.1839, 33.1804, 3.88, -0.05);	// HIP8832	5Gam2Ari		
draw_star(ctx, sunL, 8.5092, 33.9651, 2.64, 0.17);	// HIP8903	6Bet Ari	Sheratan	
draw_star(ctx, sunL, -9.0416, 29.3841, 3.82, 0.02);	// HIP9487	113Alp Psc		
draw_star(ctx, sunL, 9.9891, 37.6570, 2.01, 1.15);	// HIP9884	13Alp Ari	Hamal	
draw_star(ctx, sunL, 20.6072, 42.3416, 3.00, 0.14);	// HIP10064	4Bet Tri		
draw_star(ctx, sunL, -4.2449, 34.0437, 4.36, 0.88);	// HIP10324	65Xi 1Cet		
draw_star(ctx, sunL, 18.9753, 43.5083, 4.03, 0.02);	// HIP10670	9Gam Tri		
draw_star(ctx, sunL, -5.8317, 37.4731, 4.30, -0.05);	// HIP11484	73Xi 2Cet		
draw_star(ctx, sunL, -14.4378, 37.5794, 4.08, -0.21);	// HIP12387	82Del Cet		
draw_star(ctx, sunL, -11.9712, 39.4394, 3.47, 0.09);	// HIP12706	86Gam Cet		
draw_star(ctx, sunL, -5.5404, 41.9444, 4.27, 0.31);	// HIP12828	87Mu  Cet		
draw_star(ctx, sunL, 10.4790, 48.1987, 3.61, -0.10);	// HIP13209	41    Ari		
draw_star(ctx, sunL, 20.9741, 51.8263, 4.22, 0.34);	// HIP13254	16    Per		
draw_star(ctx, sunL, -24.5221, 38.7639, 3.89, 1.09);	// HIP13701	3Eta Eri		
draw_star(ctx, sunL, -12.5581, 44.3264, 2.54, 1.63);	// HIP14135	92Alp Cet	Menkar	
draw_star(ctx, sunL, 20.6068, 54.9023, 3.32, 1.53);	// HIP14354	25Rho Per		
draw_star(ctx, sunL, 22.4612, 56.1585, 2.09, 0.00);	// HIP14576	26Bet Per	Algol	
draw_star(ctx, sunL, 1.8544, 50.8522, 4.35, 1.03);	// HIP14838	57Del Ari		
draw_star(ctx, sunL, 10.3302, 55.2371, 4.47, 1.56);	// HIP15549			
draw_star(ctx, sunL, -9.3036, 51.1676, 3.61, 0.89);	// HIP15900	1Omi Tau		
draw_star(ctx, sunL, -8.7677, 51.9157, 3.73, -0.08);	// HIP16083	2Xi  Tau		
draw_star(ctx, sunL, -5.8840, 53.5951, 4.14, 1.11);	// HIP16369	5    Tau		
draw_star(ctx, sunL, -18.4058, 51.9603, 4.29, 0.58);	// HIP16852	10    Tau		
draw_star(ctx, sunL, 12.2188, 61.1391, 3.84, 0.02);	// HIP17448	38Omi Per		
draw_star(ctx, sunL, 4.2237, 59.4104, 3.72, -0.11);	// HIP17499	17    Tau		
draw_star(ctx, sunL, 22.1889, 63.8161, 3.77, 0.43);	// HIP17529	41Nu  Per		
draw_star(ctx, sunL, 4.5521, 59.5631, 4.30, -0.11);	// HIP17531	19    Tau		
draw_star(ctx, sunL, 4.4239, 59.6788, 3.87, -0.06);	// HIP17573	20    Tau		
draw_star(ctx, sunL, 3.9898, 59.6979, 4.14, -0.05);	// HIP17608	23    Tau		
draw_star(ctx, sunL, 4.0850, 59.9910, 2.85, -0.09);	// HIP17702	25Eta Tau	Alcyone	
draw_star(ctx, sunL, 3.9516, 60.3546, 3.62, -0.07);	// HIP17847	27    Tau		
draw_star(ctx, sunL, 11.3686, 63.1203, 2.84, 0.27);	// HIP18246	44Zet Per		
draw_star(ctx, sunL, -22.6900, 55.6393, 4.46, 0.67);	// HIP18255	32    Eri		
draw_star(ctx, sunL, 19.1504, 65.6722, 2.90, -0.20);	// HIP18532	45Eps Per		
draw_star(ctx, sunL, 14.9794, 64.9680, 3.98, 0.02);	// HIP18614	46Xi  Per		
draw_star(ctx, sunL, -7.9256, 60.6372, 3.41, -0.10);	// HIP18724	35Lam Tau		
draw_star(ctx, sunL, -14.4177, 59.9242, 3.91, 0.03);	// HIP18907	38Nu  Tau		
draw_star(ctx, sunL, 1.2950, 63.4550, 4.36, 1.06);	// HIP19038	37    Tau		
draw_star(ctx, sunL, -12.1486, 63.5851, 4.27, -0.05);	// HIP19860	49Mu  Tau		
draw_star(ctx, sunL, -5.6964, 65.8074, 3.65, 0.98);	// HIP20205	54Gam Tau		
draw_star(ctx, sunL, -3.9334, 66.8718, 3.77, 0.98);	// HIP20455	61Del1Tau		
draw_star(ctx, sunL, 0.6633, 68.2041, 4.21, 0.14);	// HIP20635	65Kap1Tau		
draw_star(ctx, sunL, -3.6513, 67.5359, 4.30, 0.05);	// HIP20648	68Del3Tau		
draw_star(ctx, sunL, 1.1421, 68.5005, 4.28, 0.26);	// HIP20711	69Ups Tau		
draw_star(ctx, sunL, -5.9641, 67.3701, 4.48, 0.26);	// HIP20713	71    Tau		
draw_star(ctx, sunL, -5.7086, 67.9568, 3.84, 0.95);	// HIP20885	77The1Tau		
draw_star(ctx, sunL, -2.5306, 68.4657, 3.53, 1.01);	// HIP20889	74Eps Tau		
draw_star(ctx, sunL, -5.8021, 67.9634, 3.40, 0.18);	// HIP20894	78The2Tau		
draw_star(ctx, sunL, -11.7031, 68.7984, 4.25, 0.18);	// HIP21402	88    Tau		
draw_star(ctx, sunL, -5.4305, 69.7905, 0.87, 1.54);	// HIP21421	87Alp Tau	Aldebaran	
draw_star(ctx, sunL, 19.0431, 73.5767, 4.25, 1.17);	// HIP21476	58    Per		
draw_star(ctx, sunL, -9.4653, 69.7588, 4.27, 0.12);	// HIP21589	90    Tau		
draw_star(ctx, sunL, 0.7513, 72.1536, 4.27, -0.11);	// HIP21881	94Tau Tau		
draw_star(ctx, sunL, -15.3468, 71.9281, 3.19, 0.48);	// HIP22449	1Pi 3Ori		
draw_star(ctx, sunL, -13.4461, 72.3700, 4.35, 0.01);	// HIP22509	2Pi 2Ori		
draw_star(ctx, sunL, -16.7345, 72.1044, 3.68, -0.16);	// HIP22549	3Pi 4Ori		
draw_star(ctx, sunL, -19.9676, 72.4951, 3.71, -0.18);	// HIP22797	8Pi 5Ori		
draw_star(ctx, sunL, -9.0266, 74.3457, 4.06, 1.16);	// HIP22957	9Omi2Ori		
draw_star(ctx, sunL, 10.4927, 76.6378, 2.69, 1.49);	// HIP23015	3Iot Aur	Hassaleh	
draw_star(ctx, sunL, -20.8140, 73.5426, 4.47, 1.37);	// HIP23123	10Pi 6Ori		
draw_star(ctx, sunL, 20.9829, 78.8385, 3.03, 0.54);	// HIP23416	7Eps Aur		
draw_star(ctx, sunL, 18.2408, 78.6308, 3.69, 1.15);	// HIP23453	8Zet Aur		
draw_star(ctx, sunL, 18.3224, 79.4438, 3.18, -0.15);	// HIP23767	10Eta Aur		
draw_star(ctx, sunL, -20.0373, 77.5746, 4.46, 1.17);	// HIP24331	17Rho Ori		
draw_star(ctx, sunL, 22.9032, 81.8555, 0.08, 0.80);	// HIP24608	13Alp Aur	Capella	
draw_star(ctx, sunL, -16.7772, 80.9483, 1.64, -0.22);	// HIP25336	24Gam Ori	Bellatrix	
draw_star(ctx, sunL, 5.4241, 82.5745, 1.65, -0.13);	// HIP25428	112Bet Tau	Alnath	
draw_star(ctx, sunL, -17.2595, 82.3911, 4.20, -0.14);	// HIP25813	32    Ori		
draw_star(ctx, sunL, -23.5141, 82.3644, 2.25, -0.18);	// HIP25930	34Del Ori	Mintaka	
draw_star(ctx, sunL, -4.6469, 83.3956, 4.32, 2.06);	// HIP25945	119    Tau		
draw_star(ctx, sunL, -13.7711, 83.6071, 4.39, -0.16);	// HIP26176	37Phi1Ori		
draw_star(ctx, sunL, -13.3304, 83.7079, 3.39, -0.16);	// HIP26207	39Lam Ori		
draw_star(ctx, sunL, -24.4673, 83.4657, 1.69, -0.18);	// HIP26311	46Eps Ori	Alnilam	
draw_star(ctx, sunL, -13.9919, 84.1278, 4.09, 0.95);	// HIP26366	40Phi2Ori		
draw_star(ctx, sunL, -2.1565, 84.7848, 2.97, -0.15);	// HIP26451	123Zet Tau		
draw_star(ctx, sunL, -19.1795, 84.5040, 4.50, -0.10);	// HIP26594	47Ome Ori		
draw_star(ctx, sunL, 15.7611, 88.2858, 3.97, 1.13);	// HIP27673	32Nu  Aur		
draw_star(ctx, sunL, -3.1174, 88.6809, 4.39, 0.59);	// HIP27913	54Chi1Ori		
draw_star(ctx, sunL, -15.9877, 88.7548, 0.45, 1.50);	// HIP27989	58Alp Ori	Betelgeuse	
draw_star(ctx, sunL, 21.5475, 89.9104, 1.90, 0.08);	// HIP28360	34Bet Aur	Menkalinan	
draw_star(ctx, sunL, 13.8126, 89.9428, 2.65, -0.08);	// HIP28380	37The Aur		
draw_star(ctx, sunL, 22.5367, 89.9878, 4.30, 1.70);	// HIP28404	35Pi  Aur		
draw_star(ctx, sunL, -13.7515, 90.6047, 4.12, 0.17);	// HIP28614	61Mu  Ori		
draw_star(ctx, sunL, -0.1333, 90.9463, 4.16, 0.84);	// HIP28734	1    Gem		
draw_star(ctx, sunL, -8.6194, 91.8514, 4.42, -0.16);	// HIP29038	67Nu  Ori		
draw_star(ctx, sunL, -9.1609, 92.9310, 4.45, -0.18);	// HIP29426	70Xi  Ori		
draw_star(ctx, sunL, -0.8489, 93.4361, 3.31, 1.60);	// HIP29655	7Eta Gem		
draw_star(ctx, sunL, 6.1429, 93.3649, 4.32, 1.02);	// HIP29696	44Kap Aur		
draw_star(ctx, sunL, -0.7810, 95.3018, 2.87, 1.62);	// HIP30343	13Mu  Gem		
draw_star(ctx, sunL, -18.6784, 96.2535, 4.39, 0.22);	// HIP30419	8Eps Mon		
draw_star(ctx, sunL, -3.0173, 96.8022, 4.13, -0.12);	// HIP30883	18Nu  Gem		
draw_star(ctx, sunL, -15.8255, 98.4819, 4.47, 0.02);	// HIP31216	13    Mon		
draw_star(ctx, sunL, -6.7038, 99.1039, 1.93, 0.00);	// HIP31681	24Gam Gem	Alhena	
draw_star(ctx, sunL, 2.1087, 99.9390, 3.06, 1.38);	// HIP32246	27Eps Gem		
draw_star(ctx, sunL, -9.7590, 100.8608, 4.49, 1.17);	// HIP32249	30    Gem		
draw_star(ctx, sunL, -10.0657, 101.2079, 3.35, 0.44);	// HIP32362	31Xi  Gem		
draw_star(ctx, sunL, -20.4597, 102.7725, 4.48, 1.10);	// HIP32578	18    Mon		
draw_star(ctx, sunL, 11.0687, 101.1249, 3.60, 0.10);	// HIP33018	34The Gem		
draw_star(ctx, sunL, -2.0009, 104.9899, 4.01, 0.90);	// HIP34088	43Zet Gem		
draw_star(ctx, sunL, 7.7923, 105.4457, 4.41, 1.26);	// HIP34693	46Tau Gem		
draw_star(ctx, sunL, -22.6848, 109.5302, 4.15, -0.01);	// HIP34769	22Del Mon		
draw_star(ctx, sunL, -5.5980, 108.7776, 3.58, 0.11);	// HIP35350	54Lam Gem		
draw_star(ctx, sunL, -0.1411, 108.5193, 3.50, 0.37);	// HIP35550	55Del Gem		
draw_star(ctx, sunL, 5.7955, 108.9586, 3.78, 1.02);	// HIP36046	60Iot Gem		
draw_star(ctx, sunL, -13.4508, 112.1882, 2.89, -0.10);	// HIP36188	3Bet CMi	Gomeisa	
draw_star(ctx, sunL, -12.7839, 112.3427, 4.33, 1.43);	// HIP36284	4Gam CMi		
draw_star(ctx, sunL, 9.8469, 109.0908, 4.16, 0.32);	// HIP36366	62Rho Gem		
draw_star(ctx, sunL, 10.1326, 110.2427, 1.58, 0.03);	// HIP36850	66Alp Gem	Castor	
draw_star(ctx, sunL, 5.2526, 111.3456, 4.06, 1.54);	// HIP36962	69Ups Gem		
draw_star(ctx, sunL, -15.9842, 115.7806, 0.40, 0.43);	// HIP37279	10Alp CMi	Procyon	
draw_star(ctx, sunL, 7.4867, 112.6285, 4.23, 1.12);	// HIP37629	75Sig Gem		
draw_star(ctx, sunL, 3.1145, 113.6666, 3.57, 0.93);	// HIP37740	77Kap Gem		
draw_star(ctx, sunL, 6.7203, 113.2176, 1.16, 0.99);	// HIP37826	78Bet Gem	Pollux	
draw_star(ctx, sunL, -17.7156, 122.2361, 4.39, 1.25);	// HIP39311			
draw_star(ctx, sunL, -22.5550, 125.1281, 4.36, 0.97);	// HIP39863	29Zet Mon		
draw_star(ctx, sunL, -10.2551, 124.2533, 3.53, 1.48);	// HIP40526	17Bet Cnc		
draw_star(ctx, sunL, 23.1402, 117.5673, 4.25, 1.55);	// HIP41075	31    Lyn		
draw_star(ctx, sunL, -22.4193, 129.8422, 3.91, -0.01);	// HIP41307			
draw_star(ctx, sunL, -12.3626, 130.2988, 4.14, 0.00);	// HIP42313	4Del Hya		
draw_star(ctx, sunL, -14.5723, 131.2030, 4.45, 1.22);	// HIP42402	5Sig Hya		
draw_star(ctx, sunL, -14.2217, 132.2973, 4.30, -0.19);	// HIP42799	7Eta Hya		
draw_star(ctx, sunL, 0.1078, 128.7220, 3.94, 1.08);	// HIP42911	47Del Cnc		
draw_star(ctx, sunL, 10.4581, 126.3504, 4.03, 1.01);	// HIP43103	48Iot Cnc		
draw_star(ctx, sunL, -11.0751, 132.3396, 3.38, 0.69);	// HIP43109	11Eps Hya		
draw_star(ctx, sunL, -11.5230, 132.9044, 4.35, -0.04);	// HIP43234	13Rho Hya		
draw_star(ctx, sunL, -10.9416, 134.5703, 3.11, 0.98);	// HIP43813	16Zet Hya		
draw_star(ctx, sunL, -5.0520, 133.6392, 4.26, 0.14);	// HIP44066	65Alp Cnc		
draw_star(ctx, sunL, 23.7465, 125.2855, 3.96, 0.46);	// HIP44248			
draw_star(ctx, sunL, -13.0271, 140.2814, 3.89, -0.06);	// HIP45336	22The Hya		
draw_star(ctx, sunL, 20.1305, 130.5801, 3.82, 0.07);	// HIP45688	38    Lyn		
draw_star(ctx, sunL, 17.9933, 131.8511, 3.14, 1.55);	// HIP45860	40Alp Lyn		
draw_star(ctx, sunL, 10.4538, 135.3012, 4.47, 1.22);	// HIP46146	1Kap Leo		
draw_star(ctx, sunL, -22.3612, 147.2656, 1.99, 1.44);	// HIP46390	30Alp Hya	Alphard	
draw_star(ctx, sunL, 7.9151, 137.8775, 4.32, 1.54);	// HIP46750	4Lam Leo		
draw_star(ctx, sunL, -14.2562, 147.6334, 3.90, 1.31);	// HIP47431	35Iot Hya		
draw_star(ctx, sunL, -3.7342, 144.2450, 3.52, 0.52);	// HIP47508	14Omi Leo		
draw_star(ctx, sunL, 9.7403, 140.7101, 2.97, 0.81);	// HIP47908	17Eps Leo	Ras Elased Australis	
draw_star(ctx, sunL, 12.3734, 141.4368, 3.88, 1.22);	// HIP48455	24Mu  Leo		
draw_star(ctx, sunL, 4.8866, 147.9079, 3.48, -0.03);	// HIP49583	30Eta Leo		
draw_star(ctx, sunL, 22.1247, 141.0216, 4.49, 0.19);	// HIP49593	21    LMi		
draw_star(ctx, sunL, -1.4002, 150.4130, 4.39, 1.45);	// HIP49637	31    Leo		
draw_star(ctx, sunL, -11.0983, 154.1090, 4.48, -0.03);	// HIP49641	15Alp Sex		
draw_star(ctx, sunL, 0.4846, 149.8294, 1.36, -0.09);	// HIP49669	32Alp Leo	Regulus	
draw_star(ctx, sunL, -22.0001, 159.3521, 3.61, 1.01);	// HIP49841	41Lam Hya		
draw_star(ctx, sunL, 11.8861, 147.5724, 3.43, 0.31);	// HIP50335	36Zet Leo		
draw_star(ctx, sunL, 8.8347, 149.6203, 2.01, 1.13);	// HIP50583	41Gam1Leo	Algieba	
draw_star(ctx, sunL, -24.6613, 165.0191, 3.83, 1.46);	// HIP51069	42Mu  Hya		
draw_star(ctx, sunL, 0.1655, 156.3890, 3.84, -0.15);	// HIP51624	47Rho Leo		
draw_star(ctx, sunL, -21.7915, 170.3505, 3.11, 1.23);	// HIP52943	Nu  Hya		
draw_star(ctx, sunL, 24.9502, 150.8929, 3.79, 1.04);	// HIP53229	46    LMi		
draw_star(ctx, sunL, 16.5125, 155.5158, 4.30, 0.02);	// HIP53417	54    Leo		
draw_star(ctx, sunL, -22.7120, 173.6731, 4.08, 1.08);	// HIP53740	7Alp Crt		
draw_star(ctx, sunL, 12.9312, 158.8610, 4.42, 0.05);	// HIP53954	60    Leo		
draw_star(ctx, sunL, 14.3462, 161.3261, 2.56, 0.13);	// HIP54872	68Del Leo	Zosma	
draw_star(ctx, sunL, 9.6855, 163.4294, 3.33, 0.00);	// HIP54879	70The Leo		
draw_star(ctx, sunL, -7.6403, 171.4782, 4.45, 0.21);	// HIP55084	74Phi Leo		
draw_star(ctx, sunL, -17.5702, 176.6745, 3.56, 1.11);	// HIP55282	12Del Crt		
draw_star(ctx, sunL, 1.7046, 168.7069, 4.05, -0.06);	// HIP55434	77Sig Leo		
draw_star(ctx, sunL, 6.1138, 167.5701, 4.00, 0.42);	// HIP55642	78Iot Leo		
draw_star(ctx, sunL, -19.6660, 179.2200, 4.06, 0.22);	// HIP55705	15Gam Crt		
draw_star(ctx, sunL, -3.0420, 175.0346, 4.30, 0.98);	// HIP56647	91Ups Leo		
draw_star(ctx, sunL, 4.5903, 174.1624, 4.04, 1.50);	// HIP57380	3Nu  Vir		
draw_star(ctx, sunL, 17.3169, 168.9864, 4.50, 0.55);	// HIP57565	93    Leo		
draw_star(ctx, sunL, 12.2726, 171.6260, 2.14, 0.09);	// HIP57632	94Bet Leo	Denebola	
draw_star(ctx, sunL, 0.6962, 177.1646, 3.59, 0.52);	// HIP57757	5Bet Vir		
draw_star(ctx, sunL, 8.5263, 177.7003, 4.12, 0.97);	// HIP58948	9Omi Vir		
draw_star(ctx, sunL, -21.7576, 192.2291, 4.02, 0.33);	// HIP59199	1Alp Crv		
draw_star(ctx, sunL, -19.6815, 191.6516, 3.02, 1.33);	// HIP59316	2Eps Crv		
draw_star(ctx, sunL, -14.5082, 190.7157, 2.58, -0.11);	// HIP59803	4Gam Crv	Gienah Ghurab	
draw_star(ctx, sunL, 1.3620, 184.8331, 3.89, 0.03);	// HIP60129	15Eta Vir		
draw_star(ctx, sunL, -12.2054, 193.4435, 2.94, -0.01);	// HIP60965	7Del Crv	Algorab	
draw_star(ctx, sunL, -11.7001, 193.8074, 4.30, 0.39);	// HIP61174	8Eta Crv		
draw_star(ctx, sunL, -18.0563, 197.3557, 2.65, 0.89);	// HIP61359	9Bet Crv	Kraz	
draw_star(ctx, sunL, 2.7834, 190.1433, 2.74, 0.37);	// HIP61941	29Gam Vir	Porrima	
draw_star(ctx, sunL, 8.6056, 191.4667, 3.39, 1.57);	// HIP63090	43Del Vir		
draw_star(ctx, sunL, 16.1982, 189.9515, 2.85, 0.93);	// HIP63608	47Eps Vir	Vindemiatrix	
draw_star(ctx, sunL, 1.7306, 198.2384, 4.38, -0.01);	// HIP64238	51The Vir		
draw_star(ctx, sunL, 22.9722, 188.9665, 4.32, 0.46);	// HIP64241	42Alp Com		
draw_star(ctx, sunL, -13.7605, 207.0097, 2.99, 0.92);	// HIP64962	46Gam Hya		
draw_star(ctx, sunL, -2.0704, 203.8401, 0.98, -0.24);	// HIP65474	67Alp Vir	Spica	
draw_star(ctx, sunL, 8.6218, 202.1397, 3.38, 0.11);	// HIP66249	79Zet Vir		
draw_star(ctx, sunL, -20.6277, 216.6675, 4.23, 0.39);	// HIP67153	1    Cen		
draw_star(ctx, sunL, -21.6327, 218.0149, 4.19, 1.52);	// HIP67457	2    Cen		
draw_star(ctx, sunL, -20.0968, 217.9189, 4.32, -0.15);	// HIP67669	3    Cen		
draw_star(ctx, sunL, 13.0443, 207.7568, 4.23, 0.12);	// HIP68520	93Tau Vir		
draw_star(ctx, sunL, -13.0741, 218.6168, 3.25, 1.09);	// HIP68895	49Pi  Hya		
draw_star(ctx, sunL, -22.1063, 222.2970, 2.06, 1.01);	// HIP68933	5The Cen	Menkent	
draw_star(ctx, sunL, 2.8907, 214.4954, 4.18, 1.32);	// HIP69427	98Kap Vir		
draw_star(ctx, sunL, 7.1776, 213.8013, 4.07, 0.51);	// HIP69701	99Iot Vir		
draw_star(ctx, sunL, -22.5301, 225.6744, 4.05, -0.03);	// HIP70090	Psi Cen		
draw_star(ctx, sunL, -23.8822, 226.7902, 4.41, -0.19);	// HIP70300			
draw_star(ctx, sunL, -21.0165, 229.9235, 4.01, -0.16);	// HIP71865			
draw_star(ctx, sunL, 9.6467, 220.1363, 3.87, 0.39);	// HIP71957	107Mu  Vir		
draw_star(ctx, sunL, -18.4252, 229.3766, 4.06, 1.36);	// HIP72010			
draw_star(ctx, sunL, 17.0767, 218.5267, 3.73, -0.01);	// HIP72220	109    Vir		
draw_star(ctx, sunL, -11.1269, 228.4766, 4.42, 1.37);	// HIP72571	58    Hya		
draw_star(ctx, sunL, 0.3053, 225.0828, 2.75, 0.15);	// HIP72622	9Alp2Lib	Zubenelgenubi	
draw_star(ctx, sunL, 11.9467, 223.1567, 4.47, 0.32);	// HIP73165	16    Lib		
draw_star(ctx, sunL, -24.0635, 234.7846, 3.13, -0.21);	// HIP73334	Kap Cen		
draw_star(ctx, sunL, 18.5214, 222.6299, 4.39, 1.03);	// HIP73620	110    Vir		
draw_star(ctx, sunL, -7.6749, 230.6839, 3.25, 1.67);	// HIP73714	20Sig Lib		
draw_star(ctx, sunL, 8.4661, 229.3755, 2.61, -0.07);	// HIP74785	27Bet Lib	Zubeneschemali	
draw_star(ctx, sunL, -11.5347, 234.9938, 4.35, 1.10);	// HIP74857	2    Lup		
draw_star(ctx, sunL, -21.4594, 238.6488, 3.22, -0.23);	// HIP75141	Del Lup		
draw_star(ctx, sunL, -17.2114, 237.4877, 3.57, 1.53);	// HIP75177	Phi1Lup		
draw_star(ctx, sunL, -21.2785, 241.4907, 2.80, -0.22);	// HIP76297	Gam Lup		
draw_star(ctx, sunL, 4.3537, 235.1397, 3.91, 1.01);	// HIP76333	38Gam Lib		
draw_star(ctx, sunL, -8.5410, 238.6063, 3.60, 1.36);	// HIP76470	39Ups Lib		
draw_star(ctx, sunL, -22.4984, 242.4348, 4.34, 1.41);	// HIP76552	Ome Lup		
draw_star(ctx, sunL, -10.0546, 239.3474, 3.66, -0.18);	// HIP76600	40Tau Lib		
draw_star(ctx, sunL, 16.2057, 235.9455, 3.54, -0.04);	// HIP77516	32Mu  Ser		
draw_star(ctx, sunL, 23.9748, 234.3412, 3.71, 0.15);	// HIP77622	37Eps Ser		
draw_star(ctx, sunL, -13.2146, 242.8363, 3.97, -0.05);	// HIP77634	5Chi Lup		
draw_star(ctx, sunL, 3.4378, 239.8737, 4.13, 1.00);	// HIP77853	46The Lib		
draw_star(ctx, sunL, -8.6341, 243.1437, 3.87, -0.20);	// HIP78104	5Rho Sco		
draw_star(ctx, sunL, -5.5104, 242.9382, 2.89, -0.18);	// HIP78265	6Pi  Sco		
draw_star(ctx, sunL, -17.4805, 245.7664, 3.42, -0.21);	// HIP78384	Eta Lup		
draw_star(ctx, sunL, -2.0209, 242.5706, 2.29, -0.12);	// HIP78401	7Del Sco	Dschubba	
draw_star(ctx, sunL, 0.9727, 243.1903, 2.56, -0.07);	// HIP78820	8Bet1Sco	Graffias	
draw_star(ctx, sunL, -15.6602, 246.7401, 4.22, -0.18);	// HIP78918	The Lup		
draw_star(ctx, sunL, 0.1854, 243.6694, 3.93, -0.05);	// HIP78933	9Ome1Sco		
draw_star(ctx, sunL, 0.0157, 243.8443, 4.31, 0.83);	// HIP78990	10Ome2Sco		
draw_star(ctx, sunL, 1.5978, 244.6443, 4.00, 0.08);	// HIP79374	14Nu  Sco		
draw_star(ctx, sunL, 17.2064, 242.3078, 2.73, 1.58);	// HIP79593	1Del Oph		
draw_star(ctx, sunL, 16.4045, 243.5152, 3.23, 0.97);	// HIP79882	2Eps Oph		
draw_star(ctx, sunL, -4.0737, 247.7985, 2.90, 0.30);	// HIP80112	20Sig Sco		
draw_star(ctx, sunL, 1.5166, 247.5508, 4.48, 1.00);	// HIP80343	4Psi Oph		
draw_star(ctx, sunL, 3.1873, 247.9801, 4.22, 0.22);	// HIP80569	7Chi Oph		
draw_star(ctx, sunL, -4.6068, 249.7612, 1.06, 1.87);	// HIP80763	21Alp Sco	Antares	
draw_star(ctx, sunL, 23.5201, 245.6010, 3.82, 0.02);	// HIP80883	10Lam Oph		
draw_star(ctx, sunL, 5.1598, 248.6676, 4.29, 0.92);	// HIP80894	8Phi Oph		
draw_star(ctx, sunL, -12.7164, 251.4693, 4.24, -0.17);	// HIP80911			
draw_star(ctx, sunL, 0.3960, 249.6280, 4.45, 0.13);	// HIP80975	9Ome Oph		
draw_star(ctx, sunL, -6.1577, 251.4556, 2.82, -0.21);	// HIP81266	23Tau Sco		
draw_star(ctx, sunL, -13.1083, 252.5911, 4.18, 1.54);	// HIP81304			
draw_star(ctx, sunL, 11.3546, 249.2320, 2.54, 0.04);	// HIP81377	13Zet Oph		
draw_star(ctx, sunL, -11.7765, 255.3333, 2.29, 1.14);	// HIP82396	26Eps Sco		
draw_star(ctx, sunL, -15.4613, 256.1530, 3.00, -0.20);	// HIP82514	Mu 1Sco		
draw_star(ctx, sunL, -15.4206, 256.2437, 3.56, -0.21);	// HIP82545	Mu 2Sco		
draw_star(ctx, sunL, -19.6822, 257.2342, 3.62, 1.39);	// HIP82729	Zet2Sco		
draw_star(ctx, sunL, 7.1594, 257.9706, 2.43, 0.06);	// HIP84012	35Eta Oph		
draw_star(ctx, sunL, -20.2223, 260.7405, 3.32, 0.44);	// HIP84143	Eta Sco		
draw_star(ctx, sunL, -3.5884, 260.0123, 4.33, 0.86);	// HIP84405	36    Oph		
draw_star(ctx, sunL, 10.2245, 260.2989, 4.32, 0.04);	// HIP84880	53Nu  Ser		
draw_star(ctx, sunL, 1.9803, 260.9062, 4.39, 0.39);	// HIP84893	40Xi  Oph		
draw_star(ctx, sunL, -1.8824, 261.3946, 3.27, -0.19);	// HIP84970	42The Oph		
draw_star(ctx, sunL, -0.9984, 262.3334, 4.16, 0.28);	// HIP85340	44    Oph		
draw_star(ctx, sunL, -6.6682, 262.8802, 4.28, 0.40);	// HIP85423	45    Oph		
draw_star(ctx, sunL, -14.0474, 264.0117, 2.70, -0.18);	// HIP85696	34Ups Sco		
draw_star(ctx, sunL, -13.8276, 264.5848, 1.62, -0.23);	// HIP85927	35Lam Sco	Shaula	
draw_star(ctx, sunL, -15.3317, 265.2539, 4.26, 1.08);	// HIP86170			
draw_star(ctx, sunL, -19.6843, 265.5983, 1.86, 0.41);	// HIP86228	The Sco	Sargas	
draw_star(ctx, sunL, 7.8956, 264.5466, 3.54, 0.26);	// HIP86263	55Xi  Ser		
draw_star(ctx, sunL, 10.4506, 265.3942, 4.24, 0.09);	// HIP86565	56Omi Ser		
draw_star(ctx, sunL, -15.6835, 266.4688, 2.39, -0.17);	// HIP86670	Kap Sco		
draw_star(ctx, sunL, -16.7536, 267.5220, 2.99, 0.51);	// HIP87073	Iot1Sco		
draw_star(ctx, sunL, -13.6616, 267.9175, 3.19, 1.19);	// HIP87261			
draw_star(ctx, sunL, 13.6262, 269.7532, 3.32, 0.99);	// HIP88048	64Nu  Oph		
draw_star(ctx, sunL, 24.7043, 270.4824, 4.42, 0.05);	// HIP88290	68    Oph		
draw_star(ctx, sunL, -7.0304, 271.2616, 2.98, 0.98);	// HIP88635	10Gam2Sgr	Nash	
draw_star(ctx, sunL, 2.3029, 273.2134, 3.84, 0.20);	// HIP89341	13Mu  Sgr		
draw_star(ctx, sunL, -13.4171, 273.6284, 3.10, 1.58);	// HIP89642	Eta Sgr		
draw_star(ctx, sunL, -6.5114, 274.5812, 2.72, 1.38);	// HIP89931	19Del Sgr	Kaus Meridionalis	
draw_star(ctx, sunL, 20.3964, 275.6777, 3.23, 0.94);	// HIP89962	58Eta Ser		
draw_star(ctx, sunL, -11.0909, 275.0792, 1.79, -0.03);	// HIP90185	20Eps Sgr	Kaus Australis	
draw_star(ctx, sunL, -22.6870, 275.0750, 3.49, -0.18);	// HIP90422	Alp Tel		
draw_star(ctx, sunL, -2.1747, 276.3173, 2.82, 1.03);	// HIP90496	22Lam Sgr	Kaus Borealis	
draw_star(ctx, sunL, 14.8813, 279.0149, 3.85, 1.32);	// HIP91117	Alp Sct		
draw_star(ctx, sunL, -3.9927, 280.1818, 3.17, -0.11);	// HIP92041	27Phi Sgr		
draw_star(ctx, sunL, 18.1476, 282.3773, 4.22, 1.09);	// HIP92175	Bet Sct		
draw_star(ctx, sunL, -3.4879, 282.3858, 2.05, -0.13);	// HIP92855	34Sig Sgr	Nunki	
draw_star(ctx, sunL, 1.6230, 283.4509, 3.52, 1.15);	// HIP93085	37Xi 2Sgr		
draw_star(ctx, sunL, 16.8075, 286.0435, 4.02, 1.08);	// HIP93429	12    Aql		
draw_star(ctx, sunL, -7.2171, 283.6395, 2.60, 0.06);	// HIP93506	38Zet Sgr		
draw_star(ctx, sunL, 0.8221, 284.9939, 3.76, 1.01);	// HIP93683	39Omi Sgr		
draw_star(ctx, sunL, 17.5282, 287.3286, 3.43, -0.10);	// HIP93805	16Lam Aql		
draw_star(ctx, sunL, -14.4440, 283.6196, 4.23, 0.52);	// HIP93825	Gam CrA		
draw_star(ctx, sunL, -5.1268, 284.8352, 3.32, 1.17);	// HIP93864	40Tau Sgr		
draw_star(ctx, sunL, -15.3517, 284.1375, 4.11, 0.04);	// HIP94114	Alp CrA		
draw_star(ctx, sunL, 1.3994, 286.2515, 2.88, 0.38);	// HIP94141	41Pi  Sgr	Albaldah	
draw_star(ctx, sunL, -16.7904, 284.0647, 4.10, 1.16);	// HIP94160	Bet CrA		
draw_star(ctx, sunL, 4.1870, 289.4491, 3.92, 0.23);	// HIP95168	44Rho1Sgr		
draw_star(ctx, sunL, -22.1825, 285.7803, 3.96, -0.09);	// HIP95241	Bet1Sgr		
draw_star(ctx, sunL, -22.5350, 285.8347, 4.27, 0.35);	// HIP95294	Bet2Sgr		
draw_star(ctx, sunL, -18.4178, 286.6395, 3.96, -0.11);	// HIP95347	Alp Sgr		
draw_star(ctx, sunL, 24.7811, 293.6304, 3.36, 0.32);	// HIP95501	30Del Aql		
draw_star(ctx, sunL, 19.9746, 295.8310, 4.36, -0.08);	// HIP96468	41Iot Aql		
draw_star(ctx, sunL, 21.4894, 300.4259, 3.87, 0.63);	// HIP97804	55Eta Aql		
draw_star(ctx, sunL, -20.6954, 292.5622, 4.12, 1.06);	// HIP98032	Iot Sgr		
draw_star(ctx, sunL, -14.4213, 294.8743, 4.37, -0.15);	// HIP98412	The1Sgr		
draw_star(ctx, sunL, -7.1412, 297.0681, 4.43, 1.64);	// HIP98688	62    Sgr		
draw_star(ctx, sunL, 18.6955, 304.9059, 3.24, -0.07);	// HIP99473	65The Aql		
draw_star(ctx, sunL, 6.9557, 303.7670, 4.30, 0.93);	// HIP100027	5Alp1Cap		
draw_star(ctx, sunL, 6.8975, 303.8559, 3.58, 0.88);	// HIP100064	6Alp2Cap		
draw_star(ctx, sunL, 4.5561, 304.0456, 3.05, 0.79);	// HIP100345	9Bet Cap		
draw_star(ctx, sunL, 16.7573, 311.7093, 4.31, 0.95);	// HIP101847	71    Aql		
draw_star(ctx, sunL, -7.0599, 307.1619, 4.13, 0.43);	// HIP102485	16Psi Cap		
draw_star(ctx, sunL, 8.0512, 311.7195, 3.78, 0.00);	// HIP102618	2Eps Aqr		
draw_star(ctx, sunL, 12.3496, 312.9591, 4.43, 1.64);	// HIP102624	3    Aqr		
draw_star(ctx, sunL, -8.9937, 307.9633, 4.12, 1.63);	// HIP102978	18Ome Cap		
draw_star(ctx, sunL, -0.6142, 313.8442, 4.08, -0.01);	// HIP104139	23The Cap		
draw_star(ctx, sunL, -8.1335, 311.8478, 4.49, 1.60);	// HIP104234	24    Cap		
draw_star(ctx, sunL, 4.7377, 316.3943, 4.50, 0.93);	// HIP104459	13Nu  Aqr		
draw_star(ctx, sunL, 24.7094, 324.4298, 4.47, 0.53);	// HIP104858	7Del Equ		
draw_star(ctx, sunL, 20.0983, 323.1057, 3.92, 0.55);	// HIP104987	8Alp Equ		
draw_star(ctx, sunL, -1.3932, 317.6829, 4.28, 0.89);	// HIP105515	32Iot Cap		
draw_star(ctx, sunL, -7.0178, 316.9404, 3.77, 1.00);	// HIP105881	34Zet Cap		
draw_star(ctx, sunL, -6.5943, 317.5872, 4.50, 0.89);	// HIP106039	36    Cap		
draw_star(ctx, sunL, 8.5916, 323.3903, 2.90, 0.83);	// HIP106278	22Bet Aqr	Sadalsuud	
draw_star(ctx, sunL, -2.5816, 321.7922, 3.69, 0.32);	// HIP106985	40Gam Cap		
draw_star(ctx, sunL, 22.0814, 331.8709, 2.38, 1.52);	// HIP107315	8Eps Peg	Enif	
draw_star(ctx, sunL, -18.3689, 317.2598, 4.35, -0.05);	// HIP107380	9Iot PsA		
draw_star(ctx, sunL, -2.6250, 323.5440, 2.85, 0.18);	// HIP107556	49Del Cap		
draw_star(ctx, sunL, -23.0768, 317.4316, 3.00, -0.08);	// HIP108085	Gam Gru		
draw_star(ctx, sunL, 10.6440, 333.3459, 2.95, 0.97);	// HIP109074	34Alp Aqr	Sadalmelik	
draw_star(ctx, sunL, -2.1014, 328.7212, 4.29, -0.08);	// HIP109139	33Iot Aqr		
draw_star(ctx, sunL, -20.1081, 322.1269, 4.50, 0.05);	// HIP109285	14Mu  PsA		
draw_star(ctx, sunL, 16.3252, 336.8225, 3.52, 0.09);	// HIP109427	26The Peg		
draw_star(ctx, sunL, 2.6892, 333.2618, 4.17, 0.98);	// HIP110003	43The Aqr		
draw_star(ctx, sunL, 8.2196, 336.7088, 3.86, -0.06);	// HIP110395	48Gam Aqr		
draw_star(ctx, sunL, 8.8316, 338.9040, 3.65, 0.41);	// HIP110960	55Zet1Aqr		
draw_star(ctx, sunL, -21.3871, 327.1939, 4.29, 0.01);	// HIP111188	17Bet PsA		
draw_star(ctx, sunL, 8.1337, 340.3978, 4.04, -0.08);	// HIP111497	62Eta Aqr		
draw_star(ctx, sunL, -17.2922, 331.3394, 4.18, -0.11);	// HIP111954	18Eps PsA		
draw_star(ctx, sunL, 17.6701, 346.1395, 3.41, -0.09);	// HIP112029	42Zet Peg		
draw_star(ctx, sunL, 18.3964, 347.9348, 4.20, 0.50);	// HIP112447	46Xi  Peg		
draw_star(ctx, sunL, -5.6789, 338.5994, 4.05, 1.57);	// HIP112716	71Tau2Aqr		
draw_star(ctx, sunL, -23.6647, 331.3428, 4.46, -0.04);	// HIP112948	22Gam PsA		
draw_star(ctx, sunL, -0.3991, 341.5764, 3.73, 1.63);	// HIP112961	73Lam Aqr		
draw_star(ctx, sunL, -8.2055, 338.8787, 3.27, 0.07);	// HIP113136	76Del Aqr		
draw_star(ctx, sunL, -23.6587, 332.2102, 4.20, 0.95);	// HIP113246	23Del PsA		
draw_star(ctx, sunL, -21.1529, 333.8738, 1.17, 0.15);	// HIP113368	24Alp PsA	Fomalhaut	
draw_star(ctx, sunL, 9.0453, 348.5793, 4.48, -0.12);	// HIP113889	4Bet Psc		
draw_star(ctx, sunL, 19.4016, 353.4719, 2.49, 0.00);	// HIP113963	54Alp Peg	Markab	
draw_star(ctx, sunL, -16.6011, 338.3478, 4.48, 0.89);	// HIP114119	86    Aqr		
draw_star(ctx, sunL, -14.5036, 340.0273, 3.68, 1.20);	// HIP114341	88    Aqr		
draw_star(ctx, sunL, -1.0611, 347.1393, 4.22, 1.55);	// HIP114724	90Phi Aqr		
draw_star(ctx, sunL, -4.0109, 346.3113, 4.24, 1.11);	// HIP114855	91Psi1Aqr		
draw_star(ctx, sunL, 7.2513, 351.4483, 3.70, 0.92);	// HIP114971	6Gam Psc		
draw_star(ctx, sunL, -4.2924, 346.7324, 4.41, -0.14);	// HIP115033	93Psi2Aqr		
draw_star(ctx, sunL, -14.7977, 343.4667, 3.96, 1.08);	// HIP115438	98    Aqr		
draw_star(ctx, sunL, 24.7963, 1.9573, 4.42, 0.62);	// HIP115623	68Ups Peg		
draw_star(ctx, sunL, -15.5854, 343.9211, 4.38, 1.46);	// HIP115669	99    Aqr		
draw_star(ctx, sunL, 9.0300, 355.1828, 4.27, 1.06);	// HIP115830	10The Psc		
draw_star(ctx, sunL, 7.1523, 357.6398, 4.13, 0.51);	// HIP116771	17Iot Psc		
draw_star(ctx, sunL, 3.4152, 356.5858, 4.49, 0.20);	// HIP116928	18Lam Psc		
draw_star(ctx, sunL, -11.6265, 350.2042, 4.49, -0.03);	// HIP116971	105Ome2Aqr		
draw_star(ctx, sunL, 6.3647, 2.5792, 4.03, 0.42);	// HIP118268	28Ome Psc		
draw_star(ctx, sunL, 22.9062, 81.8532, 0.96, 0.00);	// HIP			
draw_star(ctx, sunL, 10.1352, 110.2448, 2.85, 0.00);	// HIP	66Alp Gem		
draw_star(ctx, sunL, 24.7399, 157.3600, 4.33, 0.59);	// HIP55203	53Xi  UMa		
draw_star(ctx, sunL, 2.7825, 190.1409, 3.52, 0.00);	// HIP	29Gam Vir		
draw_star(ctx, sunL, 7.1571, 257.9681, 3.40, 0.00);	// HIP			


}

#endif




  
