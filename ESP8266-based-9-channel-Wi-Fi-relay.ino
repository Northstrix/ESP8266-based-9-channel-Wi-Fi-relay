#include <ESP8266WiFi.h> 
const char* ssid     = "Blackberry";  // Your SSID (Network's name)
const char* password = "seasidehills99"; // Password from your network
int ch1 = 14; // pin D5
int ch2 = 12; // pin D6
int ch3 = 13; // pin D7
int ch4 = 15; // pin D8
int ch5 = 16; // pin D0
int ch6 = 5;  // pin D1
int ch7 = 4;  // pin D2
int ch8 = 0;  // pin D3
int ch9 = 2;  // pin D4
WiFiServer server(80);

void setup(){
  
  Serial.begin(115200); // Baudrate
  pinMode(ch1, OUTPUT); // Setting all 9 pins as OUTPUTS
  digitalWrite(ch1, LOW); // Setting 0 to all 9 pins
  pinMode(ch2, OUTPUT);
  digitalWrite(ch2, LOW);
  pinMode(ch3, OUTPUT);
  digitalWrite(ch3, LOW);
  pinMode(ch4, OUTPUT);
  digitalWrite(ch4, LOW);
  pinMode(ch5, OUTPUT);
  digitalWrite(ch5, LOW);
  pinMode(ch6, OUTPUT);
  digitalWrite(ch6, LOW);
  pinMode(ch7, OUTPUT);
  digitalWrite(ch7, LOW);
  pinMode(ch8, OUTPUT);
  digitalWrite(ch8, LOW);
  pinMode(ch9, OUTPUT);
  digitalWrite(ch9, LOW);
  Serial.print("Connecting to the Newtork"); // This all will be displayed in the Serial Monitor
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected"); 
  server.begin(); // Starting the server
  Serial.println("Server started");
  Serial.print("IP Address of network: ");
  Serial.println(WiFi.localIP());
  Serial.println("/");
}

 

void loop(){

  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client");
  while(!client.available())  
  {
    delay(1);
  } 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  int c1 = LOW; // Setting all variables to 0 by default
  int c2 = LOW;
  int c3 = LOW;
  int c4 = LOW;
  int c5 = LOW;
  int c6 = LOW;
  int c7 = LOW;
  int c8 = LOW;
  int c9 = LOW;
  
  if(request.indexOf("/ch1=ON") != -1)

  {
    digitalWrite(ch1, HIGH); // Turn ch1 ON
    c1 = HIGH;
  }
  if(request.indexOf("/ch1=OFF") != -1)
  {
    digitalWrite(ch1, LOW); // Turn ch1 OFF
    c1 = LOW;
  }
    if(request.indexOf("/ch2=ON") != -1)

  {
    digitalWrite(ch2, HIGH); // Turn ch2 ON
    c2 = HIGH;
  }
  if(request.indexOf("/ch2=OFF") != -1)
  {
    digitalWrite(ch2, LOW); // Turn ch2 OFF
    c2 = LOW;
  }
      if(request.indexOf("/ch3=ON") != -1)

  {
    digitalWrite(ch3, HIGH); // Turn ch3 ON
    c3 = HIGH;
  }
  if(request.indexOf("/ch3=OFF") != -1)
  {
    digitalWrite(ch3, LOW); // Turn ch3 OFF
    c3 = LOW;
  }
      if(request.indexOf("/ch4=ON") != -1)

  {
    digitalWrite(ch4, HIGH); // Turn ch4 ON
    c4 = HIGH;
  }
  if(request.indexOf("/ch4=OFF") != -1)
  {
    digitalWrite(ch4, LOW); // Turn ch4 OFF
    c4 = LOW;
  }
      if(request.indexOf("/ch5=ON") != -1)

  {
    digitalWrite(ch5, HIGH); // Turn ch5 ON
    c5 = HIGH;
  }
  if(request.indexOf("/ch5=OFF") != -1)
  {
    digitalWrite(ch5, LOW); // Turn ch5 OFF
    c5 = LOW;
  }
      if(request.indexOf("/ch6=ON") != -1)

  {
    digitalWrite(ch6, HIGH); // Turn ch6 ON
    c6 = HIGH;
  }
  if(request.indexOf("/ch6=OFF") != -1)
  {
    digitalWrite(ch6, LOW); // Turn ch6 OFF
    c6 = LOW;
  }
      if(request.indexOf("/ch7=ON") != -1)

  {
    digitalWrite(ch7, HIGH); // Turn ch7 ON
    c7 = HIGH;
  }
  if(request.indexOf("/ch7=OFF") != -1)
  {
    digitalWrite(ch7, LOW); // Turn ch7 OFF
    c7 = LOW;
  }
      if(request.indexOf("/ch8=ON") != -1)

  {
    digitalWrite(ch8, HIGH); // Turn ch8 ON
    c8 = HIGH;
  }
  if(request.indexOf("/ch8=OFF") != -1)
  {
    digitalWrite(ch8, LOW); // Turn ch8 OFF
    c8 = LOW;
  }
      if(request.indexOf("/ch9=ON") != -1)

  {
    digitalWrite(ch9, HIGH); // Turn ch9 ON
    c9 = HIGH;
  }
  if(request.indexOf("/ch9=OFF") != -1)
  {
    digitalWrite(ch9, LOW); // Turn ch9 OFF
    c9 = LOW;
  }
  
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html"); // All below is a web page code written in HTML
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<meta charset=\"utf-8\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<title>ESP8266-based 9 channel Wi-Fi relay</title>"); // The name of the web page
  client.println("<head> ");
  client.print("<style>");
  client.print("   body{");
  client.print("   background-color: #181818;"); // Background color
  client.print("} ");
  client.print("   p {");
  client.print( "   color: white;"); // Text color
  client.print("</style>");
  client.print("</head>");
  client.print("<body>");
  client.print("<table style=""width:100%"" text-align: center;>"); // Creating a table to store all the elements
  client.print("  <tr>");
  client.print("  <th>");
  client.print("<p>ESP8266-based 9 channel Wi-Fi relay</p>");
  client.print("<p>Developed by Maxim Bortnikov</p>");
  client.print("<p>For more information visit: https://github.com/Northstrix/ESP8266-based-9-channel-Wi-Fi-relay </p>");
  client.print("  </th>");
  client.print("  </tr>");
  client.print("  <tr>");
  client.print("<th><p> Channel 1 is  "); // Printing the state of each channel
  if(c1 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
 // client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch1=ON\"\"><button>ON</button></a>"); // "ON" button
  client.println("<a href=\"/ch1=OFF\"\"><button>OFF</button></a><br />"); // "OFF" button
  client.print("  </th>");
  client.print(" </tr>");
  client.print(" <tr>");
  client.print("<th><p> Channel 2 is  ");
  if(c2 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
  client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch2=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/ch2=OFF\"\"><button>OFF</button></a><br />");
  client.print("  </th>");
  client.print("  <tr>");
  client.print("<th><p> Channel 3 is  ");
  if(c3 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
//  client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch3=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/ch3=OFF\"\"><button>OFF</button></a><br />");
  client.print("  </th>");
  client.print(" </tr>");
    client.print(" <tr>");
  client.print("<th><p> Channel 4 is  ");
  if(c4 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
//  client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch4=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/ch4=OFF\"\"><button>OFF</button></a><br />");
  client.print("  </th>");
  client.print(" </tr>");
      client.print(" <tr>");
  client.print("<th><p> Channel 5 is  ");
  if(c5 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
 // client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch5=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/ch5=OFF\"\"><button>OFF</button></a><br />");
  client.print("  </th>");
  client.print(" </tr>");
  client.print(" <tr>");
  client.print("<th><p> Channel 6 is  ");
  if(c6 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
//  client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch6=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/ch6=OFF\"\"><button>OFF</button></a><br />");
  client.print("  </th>");
  client.print(" </tr>");
      client.print(" <tr>");
  client.print("<th><p> Channel 7 is  ");
  if(c7 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
 // client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch7=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/ch7=OFF\"\"><button>OFF</button></a><br />");
  client.print("  </th>");
  client.print(" </tr>");
      client.print(" <tr>");
  client.print("<th><p> Channel 8 is  ");
  if(c8 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
//  client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch8=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/ch8=OFF\"\"><button>OFF</button></a><br />");
  client.print("  </th>");
  client.print(" </tr>");
      client.print(" <tr>");
  client.print("<th><p> Channel 9 is  ");
  if(c9 == HIGH)
  {
    client.print(" on </p>");
  }
  else
  {
    client.print(" off </p>");
  }
  client.print("  </th>");
  client.print("  </tr>");
//  client.print("  <br></br>");
  client.print("  <th>");
  client.println("<a href=\"/ch9=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/ch9=OFF\"\"><button>OFF</button></a><br />");
  client.print("  </th>");
  client.print(" </tr>");
  client.println("</table>");
  client.println("</body>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
