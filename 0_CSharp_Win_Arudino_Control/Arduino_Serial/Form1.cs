using System;
using System.IO.Ports;
using System.Runtime.InteropServices;
using System.Threading;
using System.Windows.Forms;

namespace Arduino_Serial
{
    public partial class Form1 : Form
    {
        SerialPort serialPort;      //Define the main serial port object
        static bool _continue;
        
        //Main form initialization only
        public Form1()
        {
            InitializeComponent();
            if (serialPort == null)
            {
                serialPort = new SerialPort("COM3", 9600);      //Common baud rate of 9600
                serialPort.Open();
                _continue = true;
            }

        }


        //Main click button to receive and dispaly data
        private void button1_Click(object sender, EventArgs e)
        {
            
            if (serialPort != null)
            {
                while (_continue)
                {
                    int readValue = 0;
                    int calibration = 0;
                    calibration = ReadValues(readValue);
                    textBox1.Text = calibration.ToString();
                    if (calibration > 100)
                    {
                        int diff = calibration - 100;
                        pBar.Value = calibration - diff;
                    } else
                    {
                        pBar.Value = calibration;
                    }
                    
                }
            } else
            {
                serialPort = new SerialPort("COM3", 9600);      //Common baud rate of 9600
                serialPort.Open();
                _continue = true;
            }
        }

        //Simple function to reach character from serial port
        private int ReadValues(int msg)
        {
            if (serialPort != null && serialPort.IsOpen)
            {
                msg = serialPort.ReadChar();
            }
            return msg;
        }

    }//End of main class
}//End of namespace
