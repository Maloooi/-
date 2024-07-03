using System;
using System.Windows.Forms;
using System.Globalization;
using Microsoft.Speech;
using Microsoft.Speech.Recognition;
using System.IO;
namespace Recognizer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            textBox1.Text = "";
            label1.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string fileName = saveFileDialog1.FileName;
                File.WriteAllText(fileName, textBox1.Text);
            }
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string fileName = openFileDialog1.FileName;
                string[] grammarFromFile = File.ReadAllLines(fileName);
                label1.Text = "Словарь загружен";

                SpeechRecognitionEngine _engine = new SpeechRecognitionEngine();
                CultureInfo cs = new CultureInfo("ru-ru");
                Choices words = new Choices();
                words.Add(grammarFromFile);
                GrammarBuilder grbi = new GrammarBuilder();
                grbi.Culture = cs;
                grbi.Append(words);

                Grammar _grammar = new Grammar(grbi);
                _engine.LoadGrammar(_grammar);
                _engine.SetInputToDefaultAudioDevice();
                _engine.SpeechRecognized += speechRecognizer;
                _engine.RecognizeAsync(RecognizeMode.Multiple);
            }
        }

        private void speechRecognizer(object sender, SpeechRecognizedEventArgs e)
        {
            if (e.Result.Confidence > 0.6)
            {
                textBox1.Text += e.Result.Text;
                textBox1.Text += " ";
            }
        }
    }
}