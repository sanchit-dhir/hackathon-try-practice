const Hello = ({title, is18plus}) => {
    let age;
    if(is18plus){
      age = <p>for 18+</p>
    }else{
      age = <p>for kids</p>
    }
  return(
    <div>
    <h1>{title}</h1>
    {age}
    </div>
  )
}
const App = () => {
  return(
    <div className="simpleBox">
      <h1 className="top">
        These are the Movies
      </h1>
      <Hello title={"Wednesday"} is18plus={false}/>
      <Hello title={"Hello Universe"} is18plus={true}/>
    </div>
  )
}

export default App
