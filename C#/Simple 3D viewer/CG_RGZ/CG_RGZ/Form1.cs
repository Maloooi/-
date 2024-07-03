using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using SharpGL;
using SharpGL.SceneGraph;
using SharpGL.SceneGraph.Primitives;
using SharpGL.Serialization;
using SharpGL.SceneGraph.Core;
using SharpGL.Enumerations;

namespace CG_RGZ
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private float _rotateX = 0;
        private float _rotateY = 0;
        private float _rotateZ = 0;
        private int _rotateDelta = 5;

        private int _moveX = 0;
        private int _moveY = 0;

        private float _scaleFactor = 1;
        private float _scaleDelta = 1;
        private float _scaleDefault = 1;

        Polygon obj = null;
        private void importObjectToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openDialog = new OpenFileDialog();
            openDialog.Filter = SerializationEngine.Instance.Filter;
            if (openDialog.ShowDialog() != DialogResult.OK) return;
            var scene = SerializationEngine.Instance.LoadScene(openDialog.FileName);
            obj = scene.SceneContainer.Children.OfType<Polygon>().FirstOrDefault();

            float[] borders = new float[3];
            obj.BoundingVolume.GetBoundDimensions(out borders[0], out borders[1], out borders[2]);
            float maxBorder = borders.Max();
            float scaleFactor = maxBorder > 10 ? 10.0f / maxBorder : 1;
            obj.Transformation.ScaleX = scaleFactor;
            obj.Transformation.ScaleY = scaleFactor;
            obj.Transformation.ScaleZ = scaleFactor;

            _scaleFactor = scaleFactor;
            _scaleDefault = scaleFactor;
            _scaleDelta = scaleFactor / 10;
        }
        void ClearToolStripMenuItemClick(object sender, EventArgs e)
        {
            obj = null;
            button7_Click_1(sender, e);
        }


        private void openGLControl1_OpenGLDraw(object sender, RenderEventArgs e)
        {
            if (obj != null) { 
                OpenGL gl = openGLControl1.OpenGL;

                gl.Clear(OpenGL.GL_COLOR_BUFFER_BIT | OpenGL.GL_DEPTH_BUFFER_BIT);
                gl.LoadIdentity();
                gl.LookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);

                gl.Rotate(_rotateX, 1.0f, 0.0f, 0.0f);
                gl.Rotate(_rotateY, 0.0f, 1.0f, 0.0f);
                gl.Rotate(_rotateZ, 0.0f, 0.0f, 1.0f);
            
                gl.Translate(_moveX, 0, 0);
                gl.Translate(0,_moveY,0);
            
                obj.Transformation.ScaleX = _scaleFactor;
                obj.Transformation.ScaleY = _scaleFactor;
                obj.Transformation.ScaleZ = _scaleFactor;
                obj.PushObjectSpace(gl);
                obj.Render(gl, RenderMode.Render);
                obj.PopObjectSpace(gl);
            }
        }
        private void openGLControl1_OpenGLInitialized(object sender, EventArgs e)
        {           
            openGLControl1.OpenGL.PolygonMode(FaceMode.FrontAndBack, PolygonMode.Lines);
            
        }
        void PolygonsToolStripMenuItemClick(object sender, EventArgs e)
        {
        	PolygonsToolStripMenuItem.Checked = true;
			lightedToolStripMenuItem.Checked = false;

            openGLControl1.OpenGL.PolygonMode(FaceMode.FrontAndBack, PolygonMode.Lines);
            openGLControl1.OpenGL.Disable(OpenGL.GL_LIGHTING);   
        }        
        void LightToolStripMenuItemClick(object sender, EventArgs e)
        {
        	PolygonsToolStripMenuItem.Checked = false;
        	lightedToolStripMenuItem.Checked = true;
  
        	openGLControl1.OpenGL.PolygonMode(FaceMode.FrontAndBack, PolygonMode.Filled);        	
        	openGLControl1.OpenGL.Enable(OpenGL.GL_LIGHTING);
        	openGLControl1.OpenGL.Enable(OpenGL.GL_LIGHT0);
            openGLControl1.OpenGL.Enable(OpenGL.GL_DEPTH_TEST);
        }


        private void button1_Click(object sender, EventArgs e)
        {
            _rotateX-= _rotateDelta;
        }
        private void button2_Click(object sender, EventArgs e)
        {
            _rotateX+= _rotateDelta;
        }
        private void button3_Click(object sender, EventArgs e)
        {
            _rotateY-= _rotateDelta;
        }
        private void button4_Click(object sender, EventArgs e)
        {
            _rotateY+= _rotateDelta;
        }
        private void button5_Click(object sender, EventArgs e)
        {
            _rotateZ-= _rotateDelta;
        }
        private void button6_Click(object sender, EventArgs e)
        {
            _rotateZ+= _rotateDelta;
        }
        private void button7_Click(object sender, EventArgs e)
        {
            _moveY++;
        }
        private void button8_Click(object sender, EventArgs e)
        {
            _moveY--;
        }
        private void button9_Click(object sender, EventArgs e)
        {
            _moveX++;
        }
        private void button10_Click(object sender, EventArgs e)
        {
            _moveX--;
        }
        private void button11_Click(object sender, EventArgs e)
        {
            _scaleFactor -= _scaleDelta;
        }
        private void button12_Click(object sender, EventArgs e)
        {
            _scaleFactor+= _scaleDelta;
        }
        private void button7_Click_1(object sender, EventArgs e)
        {
            _rotateX = 0;
            _rotateY = 0;
            _rotateZ = 0;
            _scaleFactor = _scaleDefault;
            _moveX = 0;
            _moveY = 0;
        }
    }    
}