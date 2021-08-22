using RDR2;
using RDR2.Math;
using RDR2.Native;
using RDR2.UI;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.IO.Ports;
using System.Threading;

namespace RDRHorse
{

    public class Client: Script
    {
        static SerialPort _serialPort;
        public Client()
        {
       //     Tick += OnTick;
        //    Interval = 1;
       //     _serialPort = new SerialPort();
       //     _serialPort.PortName = "COM9";//Set your board COM
       //     _serialPort.BaudRate = 115200;
       //     _serialPort.Open();
        }

        private void OnTick(object sender, EventArgs evt)
        {
       //     var speed = Function.Call<float>(Hash.GET_ENTITY_SPEED, Game.Player.Character.Handle);
            
          /*  new Thread(() =>
            {
                Thread.CurrentThread.IsBackground = false;
                
                
            }).Start();*/
       //     var val = (Int64)(speed * 100);

         //   _serialPort.WriteLine(val.ToString());
         //   var txt = new TextElement($"{(int)(speed * 100):n3}", new PointF(300f, 300f), scale: 0.8f);
          //  txt.Draw();

        }
    }
}
