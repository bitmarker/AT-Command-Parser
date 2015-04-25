#include "at_parser.h"

#define DEVICE_DESCRIPTION "MyDevice v0.0.1"

int frequency = 0;

int count = 0;

char get_port(char *value)
{

  return AT_OK;
}

char get_frequency(char *value)
{
  sprintf(value, "%d", frequency);
  return AT_OK;
}

char set_frequency(char *value)
{
  sscanf(value, "%d", &frequency);
  return AT_OK;
}

char test_frequency(char *value)
{
  Serial.println("FREQ can be between 0 and 1000");
  return AT_OK;
}



void setup()
{
  Serial.begin(9600);

  pinMode(13, OUTPUT);

  at_register_command((string_t)"PORT", (at_callback)get_port, 0, 0, 0);
  at_register_command((string_t)"FREQ", (at_callback)get_frequency, (at_callback)set_frequency, (at_callback)test_frequency, 0);
}

void process_at_commands()
{
  static String readString = "";
  char ret[50];
  char res;

  while (Serial.available())
  {
    if (Serial.available() > 0)
    {
      // Get a byte from buffer
      char c = Serial.read();

      readString += c;

      // Input is too long
      if (readString.length() > AT_MAX_TEMP_STRING)
      {
        Serial.println(AT_ERROR_STRING);
        readString = "";
      }
      else
      {
        if (c == '\r' || c == ';')
        {
          readString.trim();

          // Simple echo
          if (readString == "AT")
          {
            Serial.println(DEVICE_DESCRIPTION);
            Serial.println(AT_OK_STRING);
            readString = "";
          }
          else
          {
            // Parsing the command
            res = at_parse_line((string_t)readString.c_str(), (unsigned char*)ret);

            readString = "";

            if (res == AT_OK)
            {
              if (ms_strlen((string_t)ret) > 0)
              {
                String s_ret(ret);
                Serial.println(s_ret);
              }
              Serial.println(AT_OK_STRING);
            }
            else
            {
              Serial.println(AT_ERROR_STRING);
            }
          }
        }
      }
    } // end serial available
  } // end while
}

void loop()
{
  process_at_commands();


  count++;

  if (count > 0)
  {
    digitalWrite(13, 0);
  }

  if (count > frequency / 2)
  {
    digitalWrite(13, 1);
  }

  if (count > frequency)
  {
    count = 0;
  }
}
