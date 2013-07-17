#include <string>
#include <map>
#include "p0f_info.h"
#include <QDebug>


using namespace std;

p0f_info::p0f_info(QString ip,int type){
    ip_address=ip;
    is_client=type;
}

QString p0f_info::print(){
    QString info = ">>>>>>>>>PACKET<<<<<<<<<<< \nADDRESS "+ip_address+"\nIS_CLIENT "+is_client+"\n";
    qDebug()<<">>>>>>>>>PACKET<<<<<<<<<<<";
    qDebug()<<"ADDRESS "<<ip_address<<"\nIS_CLIENT "<<is_client;
    return info;
}



//UPTIME PACKET

QString uptime_info::print_info(){
    QString info ="\nUPTIME PACKET\n uptime "+uptime+"\nraw_sig "+raw_freq+"\n";
    //print to debug
    p0f_info::print();
    qDebug()<<"UPTIME PACKET\n"<<"uptime:"<<uptime<<"\nraw_sig "<<raw_freq;
    return info;
}

QString  uptime_info::get_uptime(){
     return uptime;
 }
 QString uptime_info::get_raw_freq(){
     return raw_freq;
 }
 void uptime_info::set_uptime(QString up_time){
     uptime=up_time;
 }
 void uptime_info::set_raw_freq(QString rawfreq){
     raw_freq=rawfreq;
 }

 //MTU INFO
 QString mtu_info::get_link(){
     return link;
 }

 QString mtu_info::print_info(){
    QString info = "\nMTU PACKET\nlink:"+link+"\nraw_mtu:"+raw_mtu+"\n";
    //print to debug
    p0f_info::print();
    qDebug()<<"MTU PACKET\n"<<"link:"<<link<<"\nraw_mtu:"<<raw_mtu;
    return info;
 }

  QString mtu_info::get_raw_mtu(){
     return raw_mtu;
 }
  void mtu_info::set_link(QString mtu_link){
      link= mtu_link;
  }
  void mtu_info::set_raw_mtu(QString mtu){
      raw_mtu=mtu;
  }

//SYN INFO
  QString syn_info::print_info(){
      QString info = "\nSYN PACKET\n os:"+os+"\ndist:"+dist+"\nparams "+params+"\nraw_sig "+raw_sig+"\n";
      //print to debug
      p0f_info::print();
      qDebug()<<"SYN PACKET\n os:"<<os<<"\ndist:"<<dist<<"\nparams "<<params<<"\nraw_sig "<<raw_sig;
      return info;
  }

  QString syn_info::get_os(){
      return os;
  }
  QString syn_info::get_dist(){
      return dist;
  }
  QString syn_info::get_params(){
      return params;
  }
  QString syn_info::get_raw_sig(){
      return raw_sig;
  }
  void syn_info::set_os(QString SO){
     os=SO;
  }
  void syn_info::set_dist(QString distance){
      dist=distance;
  }
  void syn_info::set_params(QString parameters){
      params=parameters;
  }
  void syn_info::set_raw_sig(QString sig){
      raw_sig=sig;
  }

//HTTP INFO

  QString http_info::print_info(){
      QString info ="\nHTTP PACKET\napp:"+app+"\nlang:"+lang+"\nparams "+param+"\nraw_sig "+raw_sig+"\n";
      //print to debug
      p0f_info::print();
      qDebug() << "HTTP PACKET\n"<<"app:"<<app<<"\nlang:"<<lang<<"\nparams "<<param<<"\nraw_sig "<<raw_sig;
      return info;
  }
  QString http_info::get_app(){
      return app;
  }
  QString http_info::get_lang(){
      return lang;
  }
  QString http_info::get_param(){
      return param;
  }
  QString http_info::get_raw_sig(){
      return raw_sig;
  }
  void http_info::set_app(QString application){
      app=application;
  }
  void http_info::set_lang(QString language){

      lang=language;
  }
  void http_info::set_param(QString parameters){
      param=parameters;
  }
  void http_info::set_raw_sig(QString sig){
      raw_sig=sig;
  }
