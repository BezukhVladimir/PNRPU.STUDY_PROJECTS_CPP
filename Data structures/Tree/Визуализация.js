var tree;

function setup() 
{
  createCanvas(800, 600);
  background(0);
  tree = new Tree();
  
  tree.addValue(67);
  tree.addValue(65);
  tree.addValue(76);
  tree.addValue(83);
  tree.addValue(95);
  tree.addValue(79);
  tree.addValue(81);
  tree.addValue(10);
  tree.addValue(12);
  tree.addValue(22);
  tree.addValue(17);
  tree.addValue(23);
  tree.addValue(55);
  tree.addValue(47);
  tree.addValue(54);
  tree.addValue(48);
  tree.addValue(43);
  tree.addValue(35);
  tree.addValue(36);

  console.log(tree);
  tree.traverse();

  var result = tree.search(36);
  if (result == null)
  {
    console.log('not found');
  } else {
    console.log(result);
  }
}

#https://editor.p5js.org/BezukhVladimir/sketches/lI8Ml1wbD
