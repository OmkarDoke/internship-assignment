import React from 'react'
// import "../node_modules/bootstrap/dist/css/bootstrap.min.css"

function MobileList({showDetails , changeFunction}) {
  return (
   <>

    <div className='d-flex justify-content-center'>
      <div class="card mb-3 w-50">
          <img src={showDetails.location} class="card-img-top " alt="..."/>
          <div class="card-body">
          <h5 class="card-title">{showDetails.Company} {showDetails.Model}</h5>
          <p class="card-text">RAM:{showDetails.Ram}</p>
          <p class="card-text">Storage:{showDetails.Storage}</p>
          </div>
          <button className='btn btn-primary w-25' onClick={changeFunction}>Back</button>

        </div>

  </div>

   </>
  )
}

export default MobileList