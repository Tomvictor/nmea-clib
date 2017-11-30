#include <stdio.h>
#include <string.h>

char gp_buff[] = "$GPRMC,103956.000,A,1009.9733,N,07618.6494,E,0.00,272.93,120517,,,D*6F" ;

struct GPS
{
  float latitude ;
  float longitude ;
  float speed ;
  char is_fixed ;
} location;


int main(void)
{
  printf("\nbuff :  %s\n", gp_buff);
  get_lat(gp_buff);
  get_lat_hem(gp_buff) ;
  get_lon(gp_buff) ;
  get_lon_hem(gp_buff) ;

  return 0;
}


get_lat(*buff){
  parse_nmea(buff,3);
}

get_lat_hem(*buff){
  parse_nmea(buff,4) ;
}

get_lon(*buff){
  parse_nmea(buff,5) ;
}

get_lon_hem(*buff){
  parse_nmea(buff,6) ;
}


parse_nmea(*buff,int count){
  char *p1, *p2 ;
  char temp[12];
  p1 = buff ;
  unsigned char i = 0 ;
  for(i=0;i<count;i++){
  p2 = strstr(p1,",");
  p1 = p2+1 ;
  }
  p2 = strstr(p1,",");
  memset(temp,0x0,10);
  memcpy(temp,p1,p2-p1);
  printf("\r\n%s\r\n",temp);
}
