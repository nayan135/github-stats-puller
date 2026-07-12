#include <Wire.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <SSD1306.h>
#include <Fragments.h>


#define SCREEN_Height 64
#define SCREEN_Width 128


OLED oled(128, 64, 0x3C);
FragmentManager manager(oled);

Fragment gitscreen(manager);
Fragment hcscreen(manager);


Text* txtfollowers;
Text* txtfollowing;
Text* txtRepos;
Text* txtPrivateRepos;
Text* txtCommits;
Text* txtRestricted;

//hc
Text* txtHCusername;
Text* txtHCTotal;
Text* txtHcLang;
//whyyyy is it takingg so much time to saveee thissss
WiFiClientSecure client;

const char* GITHUB_USERNAME = "nayan135";

const char* api_url = "https://api.github.com/graphql";

const char* ssid = "your wifi name";
const char* password = "your wifi password";
const int pirPin=19;
const int ObsPin=32;
const int buzzPin=18;
const int buttonPin=2;
bool buttonState;
unsigned long buzzerStart=0;
bool buzzerActive= false;
const unsigned long buzz_duration= 200;
int currentScreen=0;
unsigned long lastch= 0;
const unsigned long lastch_delay= 250;
unsigned long PIR= 0;
const unsigned long PIR_delay= 250;
unsigned long OBS= 0;
const unsigned long OBS_delay= 250;
//hyaaaa jhauu layooo
//errorr solveee kasariiii hunxaaaaa sad pf //breakkk
//guyss fix thiss onee clicking ctrl+ s just saves the fileee 
const char* TOKENN ="fgdggdgfd"; //will change it later on i know the risk but for now this is it
 int followers, following, repo,prirepo, contri, contri2;
String  username= "N/A", coding_Time="CHECK", toplang="guess?";
 const char* HACKATIME_API_KEY ="1ggdd";

unsigned long lastFetch =0;
const unsigned long RefreshInt = 15UL * 60UL * 1000UL;
void FetchgithubStats(){
 client.setInsecure();

  HTTPClient http;
  http.begin(client, api_url);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "Bearer "+ String(TOKENN));
  http.addHeader("User-Agent", "NAAESP");
 String query = "{\"query\":\"query { user(login: \\\"nayan135\\\") {  followers { totalCount } following { totalCount } repositories(privacy: PUBLIC) { totalCount } privaterepo: repositories(privacy: PRIVATE) { totalCount } contributionsCollection(from: \\\"2026-01-01T00:00:00Z\\\", to: \\\"2026-12-31T23:59:59Z\\\") { totalCommitContributions restrictedContributionsCount }} }\"}";
  int httpCode= http.POST(query);
  Serial.println(httpCode);
  if(httpCode == 200){
    String load = http.getString();
    JsonDocument doc;
deserializeJson(doc, load);
Serial.println(load);
  

  if(doc["errors"].is<JsonArray>()){
    Serial.println("Error in the queryy check it man");
  //  showMessage("GraphQL error", "check toekn");
    http.end();
    return;
  }
followers = doc["data"]["user"]["followers"]["totalCount"];
following = doc["data"]["user"]["following"]["totalCount"];
repo = doc["data"]["user"]["repositories"]["totalCount"];
prirepo = doc["data"]["user"]["privaterepo"]["totalCount"];
contri = doc["data"]["user"]["contributionsCollection"]["totalCommitContributions"];
contri2 = doc["data"]["user"]["contributionsCollection"]["restrictedContributionsCount"];

*txtfollowers = Text("Followers: "+ String(followers),0,0);
*txtfollowing = Text("Following: "+ String(following),0,10);
*txtRepos = Text("Repos: "+ String(repo),0,30);
*txtPrivateRepos =Text("Private Repo: "+ String(prirepo),0,40);
*txtCommits = Text("Commits: "+ String(contri),0,50);
*txtRestricted = Text("Res. Commit: "+ String(contri2),0,60);
}else{
  Serial.println("Http failedd: ");Serial.println(httpCode);
  Serial.println(http.getString());
 // showMessage("API ERROR", +String(httpCode));
}
http.end();
}

void Fetchhackatimestats(){
  client.setInsecure();
  HTTPClient http;

  http.begin(client,"https://hackatime.hackclub.com/api/v1/users/nayan135/stats");
 http.addHeader("Content-Type", "application/json");
 http.addHeader("Authorization", "Bearer " + String(HACKATIME_API_KEY));
 int httpCode = http.GET();
 Serial.println(httpCode);
if (httpCode == 200) {
    String payload = http.getString();

JsonDocument doc;
    DeserializationError err = deserializeJson(doc, payload);
    Serial.println(payload);
    if (err) {
      Serial.println("Hackatime JSON parse failed");
      http.end();
      return;
    }
username= doc["data"]["username"].as<String>();
coding_Time= doc["data"]["human_readable_total"].as<String>();
toplang= doc["data"]["languages"][0]["name"].as<String>();

*txtHCusername = Text("UserName "+ String(username),0,0);
*txtHCTotal = Text("Total Coding: "+ String(coding_Time),0,17);
*txtHcLang = Text("Top Lang: "+ String(toplang),0,33);
}
}

void showScreen(int screenIndex){
  oled.clearScr(true);
  if(screenIndex == 0){
    gitscreen.recycleAll();
  }else{
    hcscreen.recycleAll();
  }
}

void triggerBuzz(){
  digitalWrite(buzzPin, HIGH);
  buzzerActive = true;
  buzzerStart =millis();
}
void handlebuzzer(){
  if(buzzerActive && millis() - buzzerStart >= buzz_duration){
    digitalWrite(buzzPin, LOW);
    buzzerActive= false;
  }
}
void setup(){
  Serial.begin(115200);
  Wire.begin(21, 22); 

   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");

   Serial.println("DCC");
  
   oled.begin();       
  oled.clearScr();    
  oled.print("Hello!", 0, 0);
  oled<<"This also prints"<<20<<30;
  //oled.printAnimated("Nayan Acharyaa",0,20,40,false);
  delay(500);


//random text filler for statss

txtfollowers =new Text("Followers:-- ",0,0);
txtfollowing =new Text("Following: --",0,10);
txtRepos =new Text("Repos: --",0,30);
txtPrivateRepos =new Text("Private Repo:-- ",0,40);
txtCommits =new Text("Commits:-- ",0,50);
txtRestricted =new Text("Res. Commit:-- ",0,60);

gitscreen.add(txtfollowers);
gitscreen.add(txtfollowing);
gitscreen.add(txtRepos);
gitscreen.add(txtPrivateRepos);
gitscreen.add(txtCommits);
gitscreen.add(txtRestricted);

//same thing for HC

txtHCusername =new Text("UserName: --",0,0);
txtHCTotal =new Text("Total Coding: --",0,17);
txtHcLang =new Text("Top Lang: --",0,33);

hcscreen.add(txtHCusername);
hcscreen.add(txtHCTotal);
hcscreen.add(txtHcLang);

  
 FetchgithubStats();
 Fetchhackatimestats();
 lastFetch= millis();

    pinMode(buttonPin, INPUT);
   pinMode(pirPin, INPUT);
   pinMode(ObsPin, INPUT);
   pinMode(buzzPin, OUTPUT);


showScreen(currentScreen);
delay(1000);
Serial.println("Display initialized OK");


}

void loop(){
handlebuzzer();

if(millis() -lastFetch>=RefreshInt){
  FetchgithubStats();
  Fetchhackatimestats();
  lastFetch=millis();

if(currentScreen == 0) gitscreen.recycle();
else hcscreen.recycle();
}

buttonState = digitalRead(buttonPin);
if(buttonState == LOW && millis()- lastch >lastch_delay){
  lastch = millis();
  //to just get the 0 when it is one 
  currentScreen = (currentScreen +1)%2;
  //display(currentScreen);
  triggerBuzz();
}
if(digitalRead(pirPin)== HIGH && millis()- PIR > PIR_delay){
  PIR= millis();
  Serial.println("PIR TRIGGERED....");
  FetchgithubStats();
  if(currentScreen == 0)gitscreen.recycle();
  triggerBuzz();
}
if(digitalRead(ObsPin)== HIGH && millis()- OBS > OBS_delay){
  OBS= millis();
  Serial.println("OBSTACLE TRIGGERED....");
  Fetchhackatimestats();
  if(currentScreen == 1)hcscreen.recycle();
  triggerBuzz();
}

}