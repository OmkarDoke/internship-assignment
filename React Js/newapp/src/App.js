import React, {useState} from 'react'
import MobileList from './components/MobileList';
import "../node_modules/bootstrap/dist/css/bootstrap.min.css"
function App() {
  
let mobileList=[
        { Company:"Samsung" , Model:"Galaxy Z-Flip" , Ram:"8GB" , Storage:"128GB",location:require('./images/7A.jfif')},
        { Company:"Xiaomi" , Model:"Redmi 7A" , Ram:"2GB" , Storage:"32GB",location:require('./images/Xiaomi-Redmi-7A-7-A.jpg')},
        { Company:"One Plus" , Model:"Nord" , Ram:"4GB" , Storage:"64GB",location:require('./images/One Plus.jfif')},
        { Company:"Vivo" , Model:"S1" , Ram:"8GB" , Storage:"128GB",location:require('./images/vivo-s1-.jpg')},
        { Company:"Apple" , Model:"iPhone13" , Ram:"8GB" , Storage:"128GB",location:require('./images/iphone13.jfif')}
      ];
    const [state,setState] = useState(
      {
        isTrue: true,
        showDetails:null
      }
    );
  const changeState= () =>setState({isTrue: true,showDetails:null});
  
  return (
    
      <div className='d-flex flex-wrap justify-content-center'>
     { state.isTrue ? (

        <div className='w-25 d-flex justify-content-center flex-wrap gap-5 m-2'>
         {mobileList.map(row=> (
          <div className="card" >
            <img src={row.location} className="card-img-top" alt="..." />
            <div className="card-body">
            <h5 className="card-title">{row.Company}</h5>
            <p className="card-text">
            {row.Model}
            </p>
            <button href="#" className="btn btn-primary" 
            onClick={()=> setState({isTrue:false,
            showDetails:row})

            }
            >Show Details</button>
          </div>
      </div>

        ))}
      
      </div>
      )
      :
      (
        <MobileList  showDetails={ state.showDetails} changeFunction={changeState}/>
      )
}
      </div>
    
     
     
    
  );
  
}

export default App;


