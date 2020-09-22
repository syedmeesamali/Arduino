using System;
using System.IO.Ports;
using System.Windows.Forms;

namespace Arduino_Serial
{
    public partial class Form1 : Form
    {
        SerialPort serialPort;      //Define the main serial port object
        //Main form initialization only
        public Form1()
        {
            InitializeComponent();
            if (serialPort == null)
            {
                try
                {
                    serialPort = new SerialPort("COM6", 9600);      //Common baud rate of 9600
                    serialPort.Open();
                } catch (Exception ex)
                {
                    MessageBox.Show("Exception happened ...... !" + ex);
                }
                
            }
        }

        //Main click button to receive and dispaly data
        private void button1_Click(object sender, EventArgs e)
        {
            string valToSend;
            valToSend = textBox1.Text;
            if (serialPort.IsOpen)
            {
                serialPort.Write(valToSend);
            } else
            {
                try
                {
                    serialPort = new SerialPort("COM5", 9600);      //Common baud rate of 9600
                    serialPort.Open();
                    serialPort.Write(valToSend);
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Exception happened ...... !" + ex);
                }
            }
        }
    }//End of main class
}//End of namespace
