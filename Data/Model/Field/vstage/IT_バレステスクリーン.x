xof 0303txt 0032
template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}


Mesh {
 9;
 0.192065;4.084176;7.770325;,
 3.518102;4.084176;7.770325;,
 3.518102;2.682860;7.770325;,
 -3.133972;2.682860;7.770325;,
 -3.133972;4.084176;7.770325;,
 3.518102;1.281543;7.770325;,
 0.192065;1.281543;7.770325;,
 -3.133972;1.281543;7.770325;,
 0.192065;2.682860;7.770325;;
 8;
 3;2,0,1;,
 3;0,3,4;,
 3;6,2,5;,
 3;3,6,7;,
 3;2,8,0;,
 3;0,8,3;,
 3;6,8,2;,
 3;3,8,6;;

 MeshNormals {
  9;
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;-1.000000;0.000000;;
  8;
  3;2,0,1;,
  3;0,3,4;,
  3;6,2,5;,
  3;3,6,7;,
  3;2,8,0;,
  3;0,8,3;,
  3;6,8,2;,
  3;3,8,6;;
 }

 MeshTextureCoords {
  9;
  0.500754;0.111934;,
  0.983519;0.112256;,
  0.981134;0.496488;,
  0.015605;0.495840;,
  0.017990;0.111609;,
  0.978748;0.880717;,
  0.495983;0.880395;,
  0.013219;0.880069;,
  0.498368;0.496163;;
 }

 MeshMaterialList {
  1;
  8;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   50.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.500000;0.500000;;

   TextureFilename {
    "screen.bmp";
   }
  }
 }
}